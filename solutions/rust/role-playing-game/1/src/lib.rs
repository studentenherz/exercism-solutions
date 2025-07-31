pub struct Player {
    pub health: u32,
    pub mana: Option<u32>,
    pub level: u32,
}

impl Player {
    pub fn revive(&self) -> Option<Player> {
        match self.health {
            0 => Some(Player {
                health: 100,
                level: self.level,
                mana: match self.level {
                    10.. => Some(100),
                    _ => None,
                },
            }),
            _ => None,
        }
    }

    pub fn cast_spell(&mut self, mana_cost: u32) -> u32 {
        match self.mana {
            None => {
                self.health = if mana_cost < self.health {
                    self.health - mana_cost
                } else {
                    0
                };
                0
            }
            Some(mana) if mana >= mana_cost => {
                self.mana = Some(mana - mana_cost);
                mana_cost * 2
            }
            _ => 0,
        }
    }
}
