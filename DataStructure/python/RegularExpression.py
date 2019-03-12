import re

string = '''Luke Skywarker 02-123-4567 luke@daum.net
다스베이더 070-9999-9999 darth_vader@gmail.com
princess leia 010 2454 3457 leia@gmail.com'''

result = re.findall('\d+',string) # 숫자를 표현하는 정규화 표현식, +는 하나 이상연결된!!
print(result)
result = re.findall('\w',string) # 숫자 + 일반문자(_만)를 표현하는 정규화 표현식
print(result)
result = re.findall('[1-9]\d*',string) # 자연수를 찾는 정규화표현식, *는 0개이상 연결된!!
print(result)
result = re.findall('\d+-?\d+-?\d+',string) # ?는 있거나 없거나를 포함!!
print(result)
result = re.findall('\d+[ -]?\d+[ -]?\d+',string) # [ ]?에는 모든 문자가 있거나 없거나!!
print(result)
result = re.findall('\d{2}[ -]?\d{3}[ -]?\d{4}',string) # {n}는 이전 표현식을 n번 반복하자!!
print(result)
result = re.findall('\d{2,3}[ -]?\d{3,4}[ -]?\d{4}',string) # {1,n} 1 ~ n 번 반복가능!!
print(result)
result = re.findall('[aeiou]',string) #모음만 뽑아내기!!
print(result)
result = re.findall('[a-z]',string) # 소문자 알파벳만!!
print(result)
result = re.findall('[a-z]+',string) # 소문자 알파벳을 나열하고 싶을때!!
print(result)
result = re.findall('[가-힣]+',string) #한글 단어 찾기!!
print(result)
result = re.findall('\s',string) # 공백 문자 찾기(스페이스,탭,엔터)
print(result)
result = re.findall('\S+',string) # \S는 공백제외 모든 문자, split() = \S+
print(result)
result = re.findall('\D',string) # \D 숫자를 제외한 문자(글자+공백+특수문자)
print(result)
result = re.findall('\W',string) # \W 글자를 제외한 문자(공백+특수문자)
print(result)

