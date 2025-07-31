defmodule KitchenCalculator do
  def get_volume({_, v}), do: v

  def to_milliliter({:milliliter, v}), do: {:milliliter, v}
  def to_milliliter({:cup, v}), do: {:milliliter, v * 240}
  def to_milliliter({:fluid_ounce, v}), do: {:milliliter, v * 30}
  def to_milliliter({:teaspoon, v}), do: {:milliliter, v * 5}
  def to_milliliter({:tablespoon, v}), do: {:milliliter, v * 15}

  def from_milliliter(volume_pair, unit = :milliliter) do 
    {unit, get_volume(to_milliliter(volume_pair))}
  end
  def from_milliliter(volume_pair, unit = :cup) do 
    {unit, get_volume(to_milliliter(volume_pair)) / 240}
  end  
  def from_milliliter(volume_pair, unit = :fluid_ounce) do
    {unit, get_volume(to_milliliter(volume_pair)) / 30}
  end  
  def from_milliliter(volume_pair, unit = :teaspoon) do
    {unit, get_volume(to_milliliter(volume_pair)) / 5}
  end
  def from_milliliter(volume_pair, unit = :tablespoon) do
    {unit, get_volume(to_milliliter(volume_pair)) / 15}
  end

  def convert(volume_pair, unit), do: from_milliliter(volume_pair, unit)
end
