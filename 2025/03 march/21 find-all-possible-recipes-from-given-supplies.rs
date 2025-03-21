// find-all-possible-recipes-from-given-supplies
// https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies

use std::collections::{HashMap, HashSet, VecDeque};

impl Solution {
    pub fn find_all_recipes(
        recipes: Vec<String>, 
        ingredients: Vec<Vec<String>>, 
        supplies: Vec<String>
        ) -> Vec<String> {
            let mut res = Vec::new();
            let mut indegs = HashMap::new();
            let mut supplies: HashSet<_> = supplies.into_iter().collect();
            let mut graph = HashMap::new();

            // build graph
            for (recipe, ings) in recipes.iter().zip(ingredients.into_iter()) {
                indegs.insert(recipe.as_str(), 0);
                for ing in ings {
                    if !supplies.contains(&ing) {
                        graph.entry(ing).or_insert(vec![]).push(recipe.as_str());
                        *indegs.get_mut(recipe.as_str()).unwrap() += 1;
                    }
                }
            }

            let mut dq = indegs.iter().fold(VecDeque::new(), |mut acc, (&s, &cnt)|{
                if cnt == 0 {
                    acc.push_back(s);
                }
                acc
            });

            while !dq.is_empty() {
                let s = dq.pop_front().unwrap();
                res.push(s.to_owned());

                if let Some(v) = graph.get(s) {
                    for rec in v.iter() {
                        let cnt = indegs.get_mut(rec).unwrap();
                        *cnt -= 1;
                        if *cnt == 0 {
                            dq.push_back(rec);
                        }
                    }
                }
            }

            res
    }
}
