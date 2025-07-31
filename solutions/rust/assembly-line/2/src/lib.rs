pub fn production_rate_per_hour(speed: u8) -> f64 {
    let produced = (speed as u16 * 221) as f64;
    let success_rate = match speed {
        0..=4 => 1.0,
        5..=8 => 0.9,
        9..=10 => 0.77,
        _ => panic!("speed should be between 0 and 10 (both included)")
    };
    success_rate * produced
}

pub fn working_items_per_minute(speed: u8) -> u32 {
    (production_rate_per_hour(speed) / 60f64) as u32
}
