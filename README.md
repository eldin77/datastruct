# datastruct
###python rex 관련
## 반복 메타 문자

\* : 0회이상 반복

\+ : 1회 이상 반복

? : 0회 혹은 1회

{m} : m회 반복

{m,n} : m회부터 n회까지 반복


## 매칭 메타 문자

. : 줄바꿈 문자를 제외한 모든 문자와 매치. re.DOTALL모드로 사용하면 줄바꿈 문자포함

^ : 1.  문자열의 시작과 매치. re.MULTILINE모드에서 각 라인의 시작과 매치

$ : 1. 문자열의 마지막과 매치. 2.[]메타 기호 안에서는 메타기호로 사용되지 않고 순수한 $ 문자로 매치.

[] : 문자의 집합. [abc] a,b,c 와 매칭, [a-zA-Z0-9] 모든영문자 숫자와 매칭

| : a|b or를 의미

(): 정규식 그룹으로 묶는다.


## 이스케이프 기호
\\\ : 역슬래쉬 문자 자체를 의미.

\d : 모든 숫자와 매치.[0-9]

\D: 숫자가 아닌 문자와 매치 [^0-9]

\s: 화이트 스페이스 문자와 매치. [\t\n\r\f\v]

\S: 화이트 스페이스가 아닌 문자와 매치.[^\t\n\r\f\v]

\w: 숫자 또는 문자와 매치[a-zA-Z]

\W: 숫자 또는 문자가 아닌 것과 매치 [^a-zA-Z]

\b: 단어의 경계를 나타낸다. 단어는 영문자 , 숫자의 연속문자열로 가정

\B: \b의 반대


## 최소 매칭 정규식
*? : *와 같으나 문자열을 최소로 매칭

+? : +와 같으나 문자열을 최소로 매칭

?? : ?와 같으나 문자열을 최소로 매칭

{m,n}? : {m, n}과 같으나 문자열을 최소로 매치.


## 매칭된 문자열 추출하기

group() : 매치된 문자열을 리턴

start() : 매치된 문자열의 시작위치를 리턴

end() : 매치된 문자열의 끝 위치를 리턴

span() : 매치된 문자열의 위치 튜플을 리턴


## group method

group() : 매치된 전체 문자열을 리턴

group(n) : n번째 그룹 문자열을 리턴

groups() :  매치된 전체 그룹 문자열을 튜플 형식으로 리턴


## re가 제공하는 주요함수

compile(pattern[, flags]) : 패턴을 검색하여 정규식 객체를 리턴한다 

search(pattern, string[, flags]): 스트링을 검사해서 패턴에 맞는 문자열이 있는부부이 있는가를 찾는다,

match(pattern , string[, flags]) : 스트링의 시작부터 패턴에 맞는지 검사

split(pattern, string[, maxsplit = 0]) : 스트링을 패턴기준으로 분리 

findall(pattern, string) : 스트링에서 패턴을 만족하는 모든 문자열을 추출

sub(pattern, repl, string[, count=0]) : 스트링에서 패턴을 repl로 대치 

subn(pattern, repl, string[,count =0])  : sub와 동일하나 대치 횟수도 함께 전달.

escape(string):영문자 숫자가 아닌 문자들을 백슬래쉬 처리하여 리턴. 임의의 문자열을 정규식 패턴으로 사용할 경우유용하다.

## 플래그 사용하기

I, IGNORECASE : 대소문자 구별하지 않고 매치

L, LOCALE : /w /W /b /B를 현재의 로케일에 영향을 받게 한다.

M, MULTININE : ^가 문자열의 맨처음, 그리고 각 라인의 맨처음과 매치 $는 문자열의 맨 끝, 그리고 각 라인의 끝에 매치된다. 기본 값은 ^ 는 문자열의 맨 처음만, $는 문자열읠 맨 마지막만 매치된다.

S, DOTALL : .줄바꾸기 문자도 포함하여 매치한다. 기본값은 \n제외한 문자와 매치

U, UNICODE :  \w \W \b \B 가 유니코드 문자 특성에 의존하게 된다.

X, VERBOSE : 보기 좋은 정규식을 쑥수있게 해준다. 정규식 안의 공백은 무시된다. 공백을 사용하려면 백슬래쉬 문자로 표현해야한다. 또한 정규식 안에 # 문자를 쓰면 그주석으로 이후의 모든 문자는 무시된다.

