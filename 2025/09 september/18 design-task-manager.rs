// design-task-manager
// https://leetcode.com/problems/design-task-manager

use std::collections::{BinaryHeap, HashMap};

struct TaskManager {
    tasks: BinaryHeap<(i32, i32, i32)>,
    prs: HashMap<i32, i32>,
    usrs: HashMap<i32, i32>
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl TaskManager {

    fn new(tasks: Vec<Vec<i32>>) -> Self {
        let mut tasks_: BinaryHeap<(i32, i32, i32)> = BinaryHeap::new();
        let mut prs_: HashMap<i32, i32> = HashMap::new();
        let mut usrs_: HashMap<i32, i32> = HashMap::new();

        for triple in tasks.iter() {
            let (user_id, task_id, priority) = (triple[0], triple[1], triple[2]);
            prs_.insert(task_id, priority);
            usrs_.insert(task_id, user_id);
            tasks_.push((priority, task_id, user_id))
        }
        
        Self {
            tasks: tasks_,
            prs: prs_,
            usrs: usrs_
        }
    }
    
    fn add(&mut self, user_id: i32, task_id: i32, priority: i32) {
        self.prs.insert(task_id, priority);
        self.usrs.insert(task_id, user_id);
        self.tasks.push((priority, task_id, user_id))
    }
    
    fn edit(&mut self, task_id: i32, new_priority: i32) {
        self.prs.insert(task_id, new_priority);
        self.tasks.push((new_priority, task_id, self.usrs[&task_id]))
    }
    
    fn rmv(&mut self, task_id: i32) {
        self.prs.insert(task_id, -1);
        self.usrs.insert(task_id, -1);        
    }
    
    fn exec_top(&mut self) -> i32 {
        let (mut pr, mut tid, mut uid) = match self.tasks.pop() {
            Some(x) => x,
            None => { return -1 }
        };
        while pr != self.prs[&tid] || uid != self.usrs[&tid] {
            (pr, tid, uid) = match self.tasks.pop() {
                Some(x) => x,
                None => { return -1 }
            };
        }
        self.rmv(tid);
        uid
    }
}

/**
 * Your TaskManager object will be instantiated and called as such:
 * let obj = TaskManager::new(tasks);
 * obj.add(userId, taskId, priority);
 * obj.edit(taskId, newPriority);
 * obj.rmv(taskId);
 * let ret_4: i32 = obj.exec_top();
 */
