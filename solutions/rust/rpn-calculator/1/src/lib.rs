#[derive(Debug, Clone)]
pub enum CalculatorInput {
    Add,
    Subtract,
    Multiply,
    Divide,
    Value(i32),
}

pub fn evaluate(inputs: &[CalculatorInput]) -> Option<i32> {
    println!("{inputs:?}");
    let mut stack: Vec<i32> = vec![];

    for token in inputs.iter() {
        match token {
            CalculatorInput::Value(x) => stack.push(x.clone()),
            _ => {
                let x = stack.pop();
                let y = stack.pop();
                if x.is_none() || y.is_none() {
                    return None;
                } else {
                    match token {
                        CalculatorInput::Add => {
                            stack.push(x.unwrap() + y.unwrap());
                        }
                        CalculatorInput::Subtract => {
                            stack.push(y.unwrap() - x.unwrap());
                        }
                        CalculatorInput::Multiply => {
                            stack.push(x.unwrap() * y.unwrap());
                        }
                        CalculatorInput::Divide => {
                            stack.push(y.unwrap() / x.unwrap());
                        }
                        _ => {}
                    }
                }
            }
        }
    }

    match stack.pop() {
        Some(x) if stack.is_empty() => Some(x),
        _ => None,
    }
}
