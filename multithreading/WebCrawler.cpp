/*
1242. Web Crawler Multithreaded
https://leetcode.com/problems/web-crawler-multithreaded/
*/

using namespace std;

#include <iostream>
#include <condition_variable>
#include <mutex>
#include <thread>
#include <functional>
#include <vector>
#include <string>

namespace {
/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
public:
    
    string GetHost(const string& s) {
        string res = "";
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '/' && s[i - 1] == '/') {
                for (++i; i < s.size() && s[i] != '/'; ++i) 
                    res += s[i];                                    
                break;
            }
        }
        
        return res;
    }
    
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        
        hostName = GetHost(startUrl);        
        Q.push_back(startUrl);
        hash.insert(startUrl);
        numThreads.store(0, std::memory_order_release);  
        numElems.store(1, std::memory_order_release);
        pParser = &htmlParser;
        
        while ( numThreads != 0 || numElems != 0 )
        {            
            //Deque
            unique_lock<mutex> lk(mQ);
            
            cv.wait(lk, [this]{ return (Q.size() > 0 || numThreads == 0); });
            if (Q.size() == 0) continue;
            
            string curUrl = Q.front();
            Q.pop_front();
            --numElems;
            lk.unlock();
                                      
            res.push_back(curUrl);
                                    
            ++numThreads;
            thread* ptrT = new thread(&Solution::Update, this, curUrl);
            threads.push_back( ptrT );
        }                       
        for (auto& ptr : threads) ptr->join();    
                
        return res;
    }
    
    void Update(string startUrl)
    {        
        vector<string> strs = pParser->getUrls(startUrl);
        for (auto curUrl : strs)
        {                       
            if (GetHost(curUrl) == hostName) 
            {
                unique_lock<mutex> lk(mHash);
                if (hash.count(curUrl) == 0)
                {                    
                    hash.insert(curUrl);
                    Enque(curUrl);
                    cv.notify_all();
                }                
            }
        }
        
        --numThreads;        
        cv.notify_all();
    }       
    
    void Enque(string cur)
    {
        unique_lock<mutex> lk(mQ);
        Q.push_back(cur);        
        ++numElems;
    }
    
               
    HtmlParser* pParser;
    string hostName;
    
    deque<thread*> threads;
    atomic<int> numThreads;    
    
    deque<string> Q;
    atomic<int> numElems;
    mutex mQ;
    condition_variable cv;
    
    unordered_set<string> hash;
    mutex mHash;
    
    vector<string> res;
};

}  // namespace
