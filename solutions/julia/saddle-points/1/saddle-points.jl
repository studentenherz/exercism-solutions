function saddlepoints(M)
  points = []

  if !isempty(M)
    rowsmax = findmax(M, dims=2)[1]
    colsmin = findmin(M, dims=1)[1]

    (rows, cols) = size(M)

    for row in 1:rows
      for col in 1:cols
        if M[row, col] == rowsmax[row] == colsmin[col]
          push!(points, (row, col))
        end
      end
    end
  end

  points
end
