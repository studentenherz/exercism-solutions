defmodule NameBadge do
  def print(id, name, department) do
    idstr = if id, do:  "[#{id}] - ", else: ""
    depstr = if department, do: String.upcase(department), else: "OWNER"
    "#{idstr}#{name} - #{depstr}"
  end
end
