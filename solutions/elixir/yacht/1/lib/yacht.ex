defmodule Yacht do
  @type category ::
          :ones
          | :twos
          | :threes
          | :fours
          | :fives
          | :sixes
          | :full_house
          | :four_of_a_kind
          | :little_straight
          | :big_straight
          | :choice
          | :yacht

  @doc """
  Calculate the score of 5 dice using the given category's scoring method.
  """
  @spec score(category :: category(), dice :: [integer]) :: integer
  def score(:ones, dice), do: Enum.count(dice, &(&1 == 1))
  def score(:twos, dice), do: Enum.count(dice, &(&1 == 2)) * 2
  def score(:threes, dice), do: Enum.count(dice, &(&1 == 3)) * 3
  def score(:fours, dice), do: Enum.count(dice, &(&1 == 4)) * 4
  def score(:fives, dice), do: Enum.count(dice, &(&1 == 5)) * 5
  def score(:sixes, dice), do: Enum.count(dice, &(&1 == 6)) * 6
  def score(:choice, dice), do: Enum.sum(dice)

  def score(category, dice) do
    uniques = Enum.uniq(dice)

    case length(uniques) do
      l when l == 1 and category == :yacht ->
        50

      l when l == 1 and category == :four_of_a_kind ->
        4 * hd(uniques)

      2 ->
        case Enum.count(dice, &(&1 == hd(uniques))) do
          n when (n == 2 or n == 3) and category == :full_house -> Enum.sum(dice)
          n when n == 4 and category == :four_of_a_kind -> 4 * hd(uniques)
          n when n == 1 and category == :four_of_a_kind -> 4 * hd(tl(uniques))
          _ -> 0
        end

      5 ->
        case Enum.sort(dice) do
          sorted when sorted == [1, 2, 3, 4, 5] and category == :little_straight -> 30
          sorted when sorted == [2, 3, 4, 5, 6] and category == :big_straight -> 30
          _ -> 0
        end

      _ ->
        0
    end
  end
end
