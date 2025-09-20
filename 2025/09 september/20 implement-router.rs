// 3508. implement-router
// https://leetcode.com/problems/implement-router

use std::collections::{VecDeque,HashSet,HashMap};
use std::cmp::Ordering;

#[derive(PartialEq, Eq, Hash, Clone)]
struct Packet {
    source: i32,
    destination: i32,
    timestamp: i32,
}

struct Router {
    queue: VecDeque<Packet>,
    map: HashMap<i32, VecDeque<i32>>,
    set: HashSet<Packet>,
    n: usize,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Router {
    fn new(memoryLimit: i32) -> Self {
        let n = memoryLimit as usize;
        Self {
            queue: VecDeque::with_capacity(n),
            map: HashMap::new(),
            set: HashSet::new(),
            n
        }
    }
    
    fn add_packet(&mut self, source: i32, destination: i32, timestamp: i32) -> bool {
        let packet = Packet {
            source,
            destination,
            timestamp
        };
        if self.set.contains(&packet) { false }
        else {
            self.set.insert(packet.clone());
            self.map.entry(destination).or_insert(VecDeque::new()).push_back(timestamp);
            self.queue.push_back(packet);
            if self.queue.len() > self.n {
                self.forward_packet();
            }
            true
        }
    }
    
    fn forward_packet(&mut self) -> Vec<i32> {
        if let Some(packet) = self.queue.pop_front() {
            self.set.remove(&packet);
            self.map.get_mut(&packet.destination).unwrap().pop_front();
            vec![packet.source, packet.destination, packet.timestamp]
        } else { vec![] }
    }
    
    fn get_count(&self, destination: i32, start_time: i32, end_time: i32) -> i32 {
        (upper_bound(self.map.get(&destination).unwrap(), end_time) -
        lower_bound(self.map.get(&destination).unwrap(), start_time)) as i32
    }
}

fn lower_bound(arr: &VecDeque<i32>, target: i32) -> usize {
    arr
    .binary_search_by(|x| match x.cmp(&target) {
        Ordering::Equal => Ordering::Greater,
        ord => ord,
    })
    .unwrap_err()
}
fn upper_bound(arr: &VecDeque<i32>, target: i32) -> usize {
    arr
    .binary_search_by(|x| match x.cmp(&target) {
        Ordering::Equal => Ordering::Less,
        ord => ord,
    })
    .unwrap_err()
}

/**
 * Your Router object will be instantiated and called as such:
 * let obj = Router::new(memoryLimit);
 * let ret_1: bool = obj.add_packet(source, destination, timestamp);
 * let ret_2: Vec<i32> = obj.forward_packet();
 * let ret_3: i32 = obj.get_count(destination, startTime, endTime);
 */
