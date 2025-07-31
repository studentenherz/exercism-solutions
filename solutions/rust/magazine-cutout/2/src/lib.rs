use std::collections::HashMap;

pub fn can_construct_note(magazine: &[&str], note: &[&str]) -> bool {
    let mut map: HashMap<String, u8> = HashMap::new();
    for word in magazine {
        map.entry(word.to_string())
            .and_modify(|counter| *counter += 1)
            .or_insert(1);
    }

    for word in note {
        match map.get_mut(&word.to_string()) {
            Some(x) if *x > 0 => {
                *x -= 1;
            }
            _ => {
                return false;
            }
        }
    }

    true
}
