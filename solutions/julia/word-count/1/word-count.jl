function wordcount(sentence)
  sentence = lowercase(sentence)
  words = filter(x -> !isempty(x), map(x -> strip(x -> !(isletter(x) || isdigit(x)), x), split(sentence, x -> x != '\'' && ispunct(x) || isspace(x))))
  cnt = Dict{String,Int}()
  for word in words
    cnt[word] = get(cnt, word, 0) + 1
  end
  cnt
end
