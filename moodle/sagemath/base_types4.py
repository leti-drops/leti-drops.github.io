countries = {}

country_cnt = int(input())
for i in range(country_cnt):
	inp = input().split()
	for j in range(1, len(inp)):
		countries[inp[j]] = inp[0]

cities_cnt = int(input())
for i in range(cities_cnt):
	inp = input()
	print(countries[inp])
