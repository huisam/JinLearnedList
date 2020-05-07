## 3장 Pod: k8s에서 container 실행

### 파드가 필요한 이유?

왜 단일 컨테이너에서 여러개의 프로세스를 돌리지 않는 것인가?

* 단일 컨테이너에서 여러개의 애플리케이션을 실행하면 모든 로그가 한 컨테이너 안에 담기게 된다
* 그렇다면 그게 VM 하나로 운용하는 것과 다른게 뭐가 있냐?
* 그러니까 꼭 한 컨테이너 안에서는 한 프로세스만 돌게 하자

그래서 여러가지 특성이 있다

* 파드 안의 컨테이너는 동일한 네트워크 네임스페이스 이기 때문에 동일한 IP주소와 포트 공간을 공유한다!
* 그렇기 때문에, `포트 포워딩` 에 주의하자!

### 그렇다면, 하나의 Pod안에 모든 서비스를 넣어야 되나?

*절대 그렇지 않다*. 

그렇게 하면 Pod단위로 운용하는 의미가 없다. 

쉽게 얘기하면 Front - End Service와 Back-End Service가 하나의 Pod로 공유한다 치면,  

Pod에 대한 Scale Out이 실행될 때, 2개의 서비스는 같이 묶여서 생성되게 된다. 

이는 Pod를 운용하는 것에 대한 장점이 없다 =. **인프라스트럭쳐를 그냥 낭비하고 있다.**  

그래서 단일 Pod에 두 개의 컨테이너를 넣을꺼면

* 컨테이너를 함께 실행해야 하는가? 혹은 서로 다른 호스트에서 실행할 수 있는가?
* 여러 컨테이너가 모여서 하나의 구성 요소를 나타내는가, 혹은 개별적인 구성 요소인가?
* 컨테이너가 함께, 혹은 개별적으로 스케일링 되야 하는가?

에 대한 대답을 정의하시기 바란다. 

### Pod를 구성하는 Yaml

정말 많지만 중요한 포인트는

* Metadata: 이름, 네임스페이스, label 및 Pod에 대한 기타정보를 포함
* Spec: Pod 컨테이너, volume, 기타 데이터 등 Pod 자체에 관한 실제 명세서
* Status: Pod 상태, 각 컨테이너 설명과 상태, Pod 내부 IP, 등 현재 실행 중인 Pod에 관한 현재 정보를 포함

```yaml
apiVersion: v1 # Api version..v1/v2/v3...etc
kind: Pod # Object 종류
metadata:
 name: kubia-manual # Pod 이름
spec:
 containers:
  - image: luska/kubia # 컨테이너 이미지
    name: kubia # 컨테이너 이름
    ports: # 애플리케이션의 수신 포트번호
     - containerPort: 8080 
       protocol: TCP
```

이렇게 정의 했으면 다음과 같이 Pod를 만들 수 있다. 

```shell
kubectl create -f kubia-manual.yaml
```

그 다음 제대로 생성됬는지 확인하자!  

```shell
kubectl get pods
```

> 어떻게 하면 실행중인 컨테이너에 원격으로 명령을 내릴 수 있을까?  
>
> 해답은 바로 exec 명령어다!  
>
> ```shell
> kubectl exec monolith --stdin --tty -c monolith /bin/sh
> ```
>
> 해당 명령어는 monolith이라는 Pod에 들어가서 shell을 키겠다는 명령어다!

이 애플리케이션의 로그를 보고 싶다면?

```shell
kubectl logs [pod 이름]
```

단, 로그 파일은 하루 단위 혹은 10MB에 도달할 때 순환된다  

로컬 네트워크 포트를 파드의 포트로 포워딩하는 방법

```shell
kubectl port-forward [pod 이름] 8888:8080
```

### Pod에 Label을 붙여보자

```yaml
apiVersion: v1 # Api version..v1/v2/v3...etc
kind: Pod # Object 종류
metadata:
 name: kubia-manual-v2 # Pod 이름
 labels:
  creation_method: manual # Label 2개를 pod에 붙일 수 있다!
  env: prod
spec:
 containers:
  - image: luska/kubia # 컨테이너 이미지
    name: kubia # 컨테이너 이름
    ports: # 애플리케이션의 수신 포트번호
     - containerPort: 8080 
       protocol: TCP
```

기존에 운영중인 Pod에 label을 수정하고 싶다면?

```shell
kubectl label po kubia-manual-v2 env=debug --overwrite
```

## Service 만들어보기

Pod들을 Load Balancing할 수 있는 Service를 한번 만들어볼까?  

마찬가지로 이 친구도 `yaml` 로 다 정의되어 있다!  

```yaml
apiVersion: v1
kind: Service
metadata:
 name: kubia
spec:
 ports:
 - name: http
   port: 80 # Service가 사용될 포트 번호
   targetPort: 8080 # Service가 포워딩할 컨테이너 포트
 - name: https # 멀티 포트 서비스도 지원한다!
   port: 443
   targetPort: 8443
 selector:
  app: kubia # 해당 label에 대한 모든 Pod가 이 서비스에 포함된다!
```

만든 Service는 어떻게 조회하니?  

```shell
kubectl get svc
```

Service에 대한 자세한 정보를 조회하고 싶다면?

```shell
kubectl describe svc kubia
```

## Deployment 만들어보기

그렇다면 위에서 만든걸로 어떻게 배포를 진행할까?  

역시나 `yaml` 이다  

```yaml
apiVersion: apps/v1beta1
kind: Deployment
metadata:
 name: kubia # Deployment 이름
spec:
 replicas: 3 # 복제수
 template:
  metadata: kubia
  labels:
   app: kubia
  spec:
   containers:
   - image: luksa/kubia:v1
     name: nodejs
```

