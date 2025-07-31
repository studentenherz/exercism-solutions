def steps(number):
    if type(number) != int or number < 1:
        raise(ValueError("Only positive integers are allowed"))
    
    n = 0
    while number != 1:
        number = number / 2 if number % 2 == 0 else 3 * number + 1
        n += 1
    return n
