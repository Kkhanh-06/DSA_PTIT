t = int(input())
for _ in range(t):
    y, x = map(int, input().split())

    layer = max(x, y)
    max_val = layer * layer


    if layer % 2 == 0:
        if y == layer:
            result = max_val - (x - 1)
        else:
            result = (layer - 1) * (layer - 1) + y
    else:
        if x == layer:
            result = max_val - (y - 1)
        else:
            result = (layer - 1) * (layer - 1) + x

    print(result)
