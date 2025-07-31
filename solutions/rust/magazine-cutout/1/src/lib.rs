use std::collections::HashMap;

pub fn can_construct_note(magazine: &[&str], note: &[&str]) -> bool {
    let mut map: HashMap<String, u8> = HashMap::new();
    for word in magazine.iter() {
        match map.get_mut(&word.to_string()) {
            Some(x) => {
                *x += 1;
            }
            None => {
                map.insert(word.to_string(), 1);
            }
        }
    }

    for word in note.iter() {
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
