// 3484. design-spreadsheet
// https://leetcode.com/problems/design-spreadsheet/

use std::collections::HashMap;

struct Spreadsheet {
    sheet: HashMap::<String, i32>
}


/** 
 * `&self` means the method takes an immutable reference.
 * If you need a mutable reference, change it to `&mut self` instead.
 */
impl Spreadsheet {

    fn new(rows: i32) -> Self {
        Self {sheet: HashMap::new()}
    }
    
    fn set_cell(&mut self, cell: String, value: i32) {
        self.sheet.insert(cell, value);
    }
    
    fn reset_cell(&mut self, cell: String) {
        self.set_cell(cell, 0)
        
    }
    
    fn get_value(&mut self, formula: String) -> i32 {
        let (a, b) = formula[1..].split_once("+").unwrap();
        let x = a.parse::<i32>().unwrap_or(*self.sheet.get(a).unwrap_or(&0));
        let y = b.parse::<i32>().unwrap_or(*self.sheet.get(b).unwrap_or(&0));
        x+y
    }
}

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * let obj = Spreadsheet::new(rows);
 * obj.set_cell(cell, value);
 * obj.reset_cell(cell);
 * let ret_3: i32 = obj.get_value(formula);
 */
