use std::collections::BinaryHeap;

#[derive(Debug)]
pub struct HighScores {
    scores: Vec<u32>,
    best3: Vec<u32>,
}

impl HighScores {
    pub fn new(scores: &[u32]) -> Self {
        let mut heap = BinaryHeap::from_iter(scores);
        let mut best3 = Vec::<u32>::new();
        for _ in 0..3 {
            if let Some(&top) = heap.pop() {
                best3.push(top);
            }
        }

        Self {
            scores: Vec::from(scores),
            best3,
        }
    }

    pub fn scores(&self) -> &[u32] {
        &self.scores
    }

    pub fn latest(&self) -> Option<u32> {
        self.scores.last().copied()
    }

    pub fn personal_best(&self) -> Option<u32> {
        self.best3.first().copied()
    }

    pub fn personal_top_three(&self) -> Vec<u32> {
        self.best3.clone()
    }
}
