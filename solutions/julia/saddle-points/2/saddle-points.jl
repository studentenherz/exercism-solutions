function saddlepoints(M)
  points = []

  if !isempty(M)
    rowsmax = findmax(M, dims=2)[1]
    colsmin = findmin(M, dims=1)[1]

    points = Tuple.(findall(rowsmax .== colsmin))
  end

  points
end
