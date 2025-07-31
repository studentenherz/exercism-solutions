//
// This is only a SKELETON file for the 'Anagram' exercise. It's been provided as a
// convenience to get you started writing code faster.
//

export const findAnagrams = (word, list) => {
	const lower_word = word.toLowerCase();
	const lower_ordered_word = lower_word.split('').sort().join('');
	let anagrams = [];
	list.forEach(s => {
		if (s.length === word.length) {
			const lower_s = s.toLowerCase();
			if (lower_s !== lower_word) {
				if (lower_s.split('').sort().join('') === lower_ordered_word) {
					anagrams.push(s);
				}
			}
		}
	});

	return anagrams;
};
