pub enum CalculatorInput {
    Add,
    Subtract,
    Multiply,
    Divide,
    Value(i32),
}

pub fn evaluate(inputs: &[CalculatorInput]) -> Option<i32> {
    let mut stack: Vec<i32> = vec![];

    for token in inputs.iter() {
        match token {
            CalculatorInput::Value(x) => stack.push(x.clone()),
            _ => {
                let x = stack.pop()?;
                let y = stack.pop()?;
                match token {
                    CalculatorInput::Add => {
                        stack.push(x + y);
                    }
                    CalculatorInput::Subtract => {
                        stack.push(y - x);
                    }
                    CalculatorInput::Multiply => {
                        stack.push(x * y);
                    }
                    CalculatorInput::Divide => {
                        stack.push(y / x);
                    }
                    _ => {}
                }
            }
        }
    }

    match stack.pop() {
        Some(x) if stack.is_empty() => Some(x),
        _ => None,
    }
}
