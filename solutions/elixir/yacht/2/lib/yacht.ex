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
  def score(:little_straight, dice), do: if(Enum.sort(dice) == [1, 2, 3, 4, 5], do: 30, else: 0)
  def score(:big_straight, dice), do: if(Enum.sort(dice) == [2, 3, 4, 5, 6], do: 30, else: 0)

  def score(category, dice) do
    uniques = Enum.uniq(dice)
    len = length(uniques)
    head_count = Enum.count(dice, &(&1 == hd(uniques)))

    case {category, len} do
      {:yacht, 1} ->
        50

      {:four_of_a_kind, 1} ->
        4 * hd(uniques)

      {:four_of_a_kind, 2} when head_count == 4 ->
        4 * hd(uniques)

      {:four_of_a_kind, 2} when head_count == 1 ->
        4 * hd(tl(uniques))

      {:full_house, 2} when head_count == 3 or head_count == 2 ->
        Enum.sum(dice)

      _ ->
        0
    end
  end
end
