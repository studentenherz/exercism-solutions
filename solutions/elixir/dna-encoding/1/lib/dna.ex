defmodule DNA do
  def encode_nucleotide(code_point) do
    case code_point do
      ?A -> 0b0001
      ?C -> 0b0010
      ?G -> 0b0100
      ?T -> 0b1000
      ?\s -> 0b0000
    end
  end

  def decode_nucleotide(encoded_code) do
    case encoded_code do
      0b0001 -> ?A
      0b0010 -> ?C
      0b0100 -> ?G
      0b1000 -> ?T
      0b0000 -> ?\s
    end
  end

  def encode(dna) do
    do_encode(dna, <<>>)
  end

  def decode(<<>>), do: []

  def decode(<<nucleotide::4, rest::bitstring>>) do
    [decode_nucleotide(nucleotide) | decode(rest)]
  end

  defp do_encode([], encoded), do: encoded

  defp do_encode([head | tail], encoded) do
    do_encode(tail, <<encoded::bitstring, encode_nucleotide(head)::4>>)
  end
end
