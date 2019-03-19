## Network 정리

### [1장] - TCP
**About**
> Transport Layer에서 사용하는 프로토콜로 <code>**신뢰성**</code>을 보장하는 Connective Service이다.
> Segmant 단위로 패킷을 보내기 위해 **IP**를 바탕으로 목적지와 출발지를 정하게 된다!!!
> 기본적인 연결 방식은 **3-way-handshaking**으로 연결 설정하고, 끊을 때는 **4-way-handshaking**으로 연결 해제한다!!
>* TCP가 제공하는 특징들
>> 1. Flow Control : 흐름제어 - 데이터 처리 속도를 조절하여 수신자의 <code>오버플로우</code>를 방지한다
>> 2. Congestion Control : 혼잡제어 - 네트워크 내의 패킷수가 <code>넘치지</code> 않게 방지한다
>> 3. Realiable Service : 높은 신뢰성 - 연결 기반 통신이므로 신뢰성이 높다!

**3-way-handshake**


<img src="https://user-images.githubusercontent.com/34855745/54589277-93e7b180-4a68-11e9-9033-7cdba0d8a70f.png" width="500" height="250">


> 1.Client -> Server : SYN

>* SYN 플래그 비트를 1로 설정하고, Request 요청 세그먼트 전송

> 2.Server -> Client : SYN + ACK

>* Server가 요청을 수락했으며 SYN과 ACK 플래그 비트를 1로 설정한 세그먼트를 전송

> 3.Client -> Server : ACK

>* Client가 성공적으로 Server와 연결이 되었으며, 전송할 데이터가 있다면 지금 전송할 수 있다!

<img src="https://user-images.githubusercontent.com/34855745/54589736-d1007380-4a69-11e9-9231-fe37ed8e5a90.png" width="500" height="400">

> 1.Client -> Server : FIN

>* FIN 플래그를 1로 설정하고, Client는 Server에게 연결 종료 세그먼트 전송

> 2.Server -> Client : ACK

>* Server는 알겠다고 ACK 응답을 Client에게 보내고, 마저 보낼 데이터가 있으면 더 보낸다.

> 3.Server -> Client : FIN

>* Server의 모든 데이터 전송이 끝나고, 합의하에 종료가 성립된다

> 4.Client -> Server : ACK

>* Client는 확인했다는 ACK 세그먼트를 서버에게 전송한다.

> TCP Header안의 플래그 정보들
>* SYN(Synchronize Sequence Number)
>> 연결 설정 = 000010
>* ACK(Acknowledgement)
>> 응답 확인 = 010000
>* FIN(Finish)
>> 연결 해제 = 000001

>* [TCP 관련 Java Project](https://github.com/huisam/Chatting_Talk)
