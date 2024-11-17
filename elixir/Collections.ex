#Lists
xs = ["something", :sim, 3.14]

IO.inspect(xs)
# Appending is slow
xs = xs ++ [2]
IO.inspect(xs)
# Prepending is faster way of append stuff to list
xs = [2 | xs]
IO.inspect(xs)

# List Subtraction
["something", :sim, 3.14] -- [3.14]

#List tail
x = tl xs
IO.inspect(x)

#List head
IO.puts(hd xs)

[head | tail] = xs
IO.puts(head)

#Maps
map = %{:foo => "bar", "hello" => "world"}
IO.inspect(map)

map2 = %{foo: "bar", hello: "world"}
IO.inspect(map2)

IO.puts(map.foo)

#Modify a map
new = %{map | foo: "nao"}
IO.inspect(new)
