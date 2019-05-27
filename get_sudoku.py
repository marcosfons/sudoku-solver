import requests
import json
import os
os.system('clear')
url = 'http://www.cs.utep.edu/cheon/ws/sudoku/new/?size=9'

# level = input('Digite o nível de dificuldade: ')
level = '1'
url += '&level=' + str(level)

j = json.loads(requests.get(url).text)

sudoku = []
for i in range(0, 9):
    sudoku.append([0,0,0,0,0,0,0,0,0])

for square in j['squares']:
    sudoku[square['x']][square['y']] = square['value']

# print(sudoku)
print('int tabuleiro[9][9] = {')
for i in range(0, 9):
    ue = str(sudoku[i]) + ','
    print(ue.replace('[', '{').replace(']', '}'))
print('};')