### [2장] - HTTP

**About**
> Tranport Layer의 연결(*UDP TCP*)를 기반으로한 **Application Layer**의 연결방식
> 그럼 바로 Request와 Response를 분석해보자

* <u>Request Header</u>
```
curl -v -G localhost:8080/hwbackend01/index.html
GET /hwbackend01/index.html HTTP/1.1 ---- (1)
Host: localhost:8080                 ---- (2)
User-Agent: curl/7.55.1              ---- (3)
Accept: */*                          ---- (4)
```
>* 1.HTTP 메소드명 : GET, POST, PUT, DELETE, PATCH, OPTIONS, HEAD, TRACE, CONNECT
>* 2.Host : 요청하는 서버에 대한 IP번호와 Port번호 ( **IP:Port** )
>* 3.User-Agent : 클라이언트 소프트웨어 명칭 버전
>* 4.Accept : 클라이언트가 원하는 미디어 타입
>> <code>* / *</code> : 모든 미디어 타입

>> <code>image / *</code> : 모든 이미지 유형

>> <code>text / html</code> : text로 이루어진 html만 원한다

* Response Header
```
HTTP/1.1 200                                 -- (1)
Accept-Ranges: bytes                         -- (2)
ETag: W/"629-1552900496358"                  -- (3)
Last-Modified: Mon, 18 Mar 2019 09:14:56 GMT -- (4)
Content-Type: text/html                      -- (5)
Content-Length: 629                          -- (6)
Date: Thu, 21 Mar 2019 07:46:00 GMT          -- (7)
```
>* 1.HTTP/버전 상태응답코드 : 200 **OK**, 300 **리다이렉션**, 403 **요청 거부**, 404 **찾을 수 없음**, 502 **Bad Gateway**
>> 위키백과 참조 - [자세한 링크](https://ko.wikipedia.org/wiki/HTTP_%EC%83%81%ED%83%9C_%EC%BD%94%EB%93%9C)
>* 2.Accept-Ranges : 받아들일 수 있는 컨텐츠 타입
>* 3.ETag : 고유 식별자 태그(***리소스***에 대한 구분 가능)
>* 4.Last-Modified : 해당 리소르르 마지막으로 갱신한 날짜
>* 5.Content-Type : 해당 리소스의 타입
>* 6.Content-Length : 해당 리소스의 길이
>* 7.Date : HTTP 메세지를 생성한 날짜

+ 추가로 캐쉬 / 쿠키 / 세션

> **Cache**
>- 물리적으로 존재하는 버퍼 형태의 고속 기억장치

**Cookie**
>- Client에서 저장하여, 다음에 Server로 접속할 때 Key값으로 편하고 빠르게 접속한다
>- Server는 Client들의 쿠키를 바탕으로 사용자에 대한 *상태 감시와 참조*가 가능!!

**Session**
>- Server는 일정 시간동안 같은 브라우저로부터 들어오는 요청을 하나의 **상태**로 보고 **상태**를 유지한다.
>- 브라우저가 종료하면 삭제됨