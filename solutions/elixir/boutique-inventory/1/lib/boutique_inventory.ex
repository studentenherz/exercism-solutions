defmodule BoutiqueInventory do
  def sort_by_price(inventory) do
    Enum.sort(inventory, &(&1[:price] <= &2[:price]))
  end

  def with_missing_price(inventory) do
    inventory
    |> Enum.filter(&(&1[:price] == nil))
  end

  def update_names(inventory, old_word, new_word) do
    inventory
    |> Enum.map(fn item ->
      %{item | name: String.replace(item[:name], old_word, new_word)}
    end)
  end

  def increase_quantity(item, count) do
    %{
      item
      | quantity_by_size:
          item[:quantity_by_size]
          |> Enum.map(fn {key, value} -> {key, value + count} end)
          |> Enum.into(%{})
    }
  end

  def total_quantity(item) do
    item[:quantity_by_size]
    |> Enum.reduce(0, fn {_, val}, acc -> val + acc end)
  end
end
