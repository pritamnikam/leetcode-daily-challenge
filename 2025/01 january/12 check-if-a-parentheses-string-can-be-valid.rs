// 2116. check-if-a-parentheses-string-can-be-valid
// https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid

impl Solution {
    fn scan(s: &String, locked: &String, ch1: char, ch2: char) -> bool {
        let s = if ch1 == '(' { s.chars().collect::<Vec<char>>() } 
                else { s.chars().rev().collect::<Vec<char>>() };
        
        let locked = if ch1 == '(' { locked.chars().collect::<Vec<char>>() }
                     else { locked.chars().rev().collect::<Vec<char>>() };
        
        let (mut balance, mut available) = (0i32, 0i32);
        
        for i in 0..s.len() {
            if locked[i] == '0' {
                available += 1;
                continue;
            }
            if s[i] == ch1 { balance += 1; }
            if s[i] == ch2 { balance -= 1; }
            if balance >= 0 { continue; }
            
            if available == 0 { return false }
            available -= 1;
            balance += 1;
        }
        
        true
    }

    pub fn can_be_valid(s: String, locked: String) -> bool {
        if s.len() % 2 != 0 {
            return false;
        }

        Self::scan(&s, &locked, '(', ')') 
            && Self::scan(&s, &locked, ')', '(')
    }
}
