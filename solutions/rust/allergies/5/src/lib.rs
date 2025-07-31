use strum::IntoEnumIterator;
use strum_macros::EnumIter;

pub struct Allergies {
    score: u32,
    _allergies: Vec<Allergen>,
}

#[derive(Debug, PartialEq, Eq, EnumIter, Clone, Copy)]
pub enum Allergen {
    Eggs,
    Peanuts,
    Shellfish,
    Strawberries,
    Tomatoes,
    Chocolate,
    Pollen,
    Cats,
}

impl Allergen {
    pub fn value(&self) -> u32 {
        1 << (*self as usize)
    }
}

impl Allergies {
    pub fn new(score: u32) -> Self {
        Allergies {
            score,
            _allergies: Allergen::iter()
                .filter(|allergen| score & allergen.value() != 0)
                .collect(),
        }
    }

    pub fn is_allergic_to(&self, allergen: &Allergen) -> bool {
        self.score & allergen.value() != 0
    }

    pub fn allergies(&self) -> Vec<Allergen> {
        self._allergies.clone()
    }
}
