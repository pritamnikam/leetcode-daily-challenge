// product-of-the-last-k-numbers
// https://leetcode.com/problems/product-of-the-last-k-numbers/

struct ProductOfNumbers {
    ls: Vec<i32>,
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl ProductOfNumbers {

    fn new() -> Self {
        Self { ls: vec![] }
    }
    
    fn add(&mut self, num: i32) {
        self.ls.push(num)
    }
    
    fn get_product(&self, k: i32) -> i32 {
        self.ls[self.ls.len() - k as usize..].iter().product()
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * let obj = ProductOfNumbers::new();
 * obj.add(num);
 * let ret_2: i32 = obj.get_product(k);
 */
