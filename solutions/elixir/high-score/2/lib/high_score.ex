defmodule HighScore do
  @default_score 0

  def new() do
    %{}
  end

  def add_player(scores, name, score \\ @default_score) do
    Map.merge(scores, %{name => score})
  end

  def remove_player(scores, name) do
    Map.drop(scores, [name])
  end

  def reset_score(scores, name) do
    Map.update(scores, name, @default_score, fn _ -> @default_score end)
  end

  def update_score(scores, name, score) do
    Map.update(scores, name, score, fn value -> value + score end)
  end

  def get_players(scores) do
    Map.keys(scores)
  end
end
