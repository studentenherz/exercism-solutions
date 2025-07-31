defmodule HighSchoolSweetheart do
  def first_letter(name) do
    name
    |> String.trim_leading()
    |> String.first()
  end

  def initial(name) do
    (name |> first_letter() |> String.upcase()) <> "."
  end

  def initials(full_name) do
    [name, surname] = String.split(full_name)
    initial(name) <> " " <> initial(surname)
  end

  def pair(full_name1, full_name2) do
    i1 = initials(full_name1)
    i2 = initials(full_name2)

    """
         ******       ******
       **      **   **      **
     **         ** **         **
    **            *            **
    **                         **
    **     #{i1}  +  #{i2}     **
     **                       **
       **                   **
         **               **
           **           **
             **       **
               **   **
                 ***
                  *
    """
  end
end
