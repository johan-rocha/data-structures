sum = 0

entrada = "1000000 925000 1000000 845632 1000000 400000 400000 1000000 1000000 1000000 1000000 1000000"
vector_int = [int(valor) for valor in entrada.split()]
for i in vector_int:
    sum += i

print(f"Soma = {sum}")
media = sum/12
print(f"Media = {media}")