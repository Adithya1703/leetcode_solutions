def int_sqrt(n):
    if n == 0 or n == 1:
        return n  # Base cases

    x = n  # Start with n as the initial guess
    while True:
        new_x = (x + n // x) // 2  # Integer division to avoid float values
        if new_x >= x:  # If no more improvement, return result
            return x
        x = new_x  # Update x for the next iteration