defmodule Username do
  def sanitize([]), do: []

  def sanitize([head | tail]) do
    # ä becomes ae
    # ö becomes oe
    # ü becomes ue
    # ß becomes ss

    # Please implement the sanitize/1 function
    case head do
      ?_ ->
        [head | sanitize(tail)]

      head when ?a <= head and head <= ?z ->
        [head | sanitize(tail)]

      ?ä ->
        [?a | [?e | sanitize(tail)]]

      ?ö ->
        [?o | [?e | sanitize(tail)]]

      ?ü ->
        [?u | [?e | sanitize(tail)]]

      ?ß ->
        [?s | [?s | sanitize(tail)]]

      _ ->
        sanitize(tail)
    end
  end
end
