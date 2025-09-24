// 166. fraction-to-recurring-decimal
// https://leetcode.com/problems/fraction-to-recurring-decimal

impl Solution {
    pub fn fraction_to_decimal(numerator: i32, denominator: i32) -> String {
        if numerator == 0 || denominator == 0 {
            "0".into()
        } else {
            let mut s = String::new();
            if numerator.signum() * denominator.signum() < 0 {
                s.push('-');
            }
            let mut n = (numerator as i64).abs();
            let     d = (denominator as i64).abs();
            let mut i = 0;

            // Find the start of the cycle and its period.
            let cyc = floyd(|n| (n % d) * 10, n);
            let lam = cyc.0;
            let mu  = if cyc.1 != 0 { cyc.1 } else { cyc.1 + 1 };

            // Build the output string.
            while n != 0 && i < lam + mu {
                if i == 1 {
                    s.push('.');
                }
                if i == mu {
                    s.push('(');
                }
                s.push_str(&(n / d).to_string());
                n %= d;
                n *= 10;
                i += 1;
                if i == mu + lam {
                    s.push(')');
                }
            }
            s
        }
    }
}

/// Find the start of a cycle `mu` and its period `lam`.
/// Function returns `(lam, mu)` - period and start.
///
fn floyd<F>(f: F, x0: i64) -> (usize, usize) 
where
    F: Fn(i64) -> i64
{   
    let mut tort = f(x0);
    let mut hare = f(f(x0));
    let mut mu   = 0;
    let mut lam  = 1;

    while tort != hare {
        tort = f(tort);
        hare = f(f(hare));
    }
    tort = x0;
    while tort != hare {
        tort = f(tort);
        hare = f(hare);
        mu += 1;
    }
    hare = f(tort);
    while tort != hare {
        hare = f(hare);
        lam += 1;
    }
    (lam, mu)
}
