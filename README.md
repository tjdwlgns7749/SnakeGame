# SnakeGame

C++ 을 활용해서 만든 뱀게임입니다.

**클래스 구성**

![뱀게임 클래스](https://user-images.githubusercontent.com/82795868/206752972-001de5d5-6d8d-4449-b5af-e26f92a4d1fb.png)

**소스.cpp**

PlayerManager를 객체로 1개 생성하여 게임시작


**Block.cpp / Block.h**

![이미지1](https://user-images.githubusercontent.com/82795868/206752721-e1676071-7545-4435-8e7d-d8f2ae1c6259.png)

구조체를 활용하여 블럭모양 / 블럭종류 / 현재좌표 / 이전좌표를 저장

![이미지2](https://user-images.githubusercontent.com/82795868/206752881-679a635b-ed40-46dc-801f-fa707234d53c.png)

연결리스트로 맵 테두리 블록 / 장애물블록 / 음식블록 관리하며 음식의 수(10개 제한)와 리젠시간 관리


**GameManager.cpp/GameManager.h**

![이미지3](https://user-images.githubusercontent.com/82795868/206753172-80dfb829-6cce-4214-8228-794bd86031a6.png)

Snake와 Block 클래스를 객체로 생성하여 직접적으로 함수를 호출하여 게임관리
DrawManager를 이용하여 화면에 그려줄 함수 호출
스코어 / 장애물 수/ 게임시간 / 맵의 넓이 관리

**Snake.cpp/Snake.h**

![이미지4](https://user-images.githubusercontent.com/82795868/206753327-ed54cae0-d71e-429a-983b-0fad02c83572.png)

enum을 통해 뱀의 방향(상태)를 저장

![이미지5](https://user-images.githubusercontent.com/82795868/206753383-a6b3610e-0371-4854-8c26-a86ec38f4bd5.png)

연결리스트를 통해 Block.h에 있는 BlockState구조체를 가져와서 사용

뱀을 그려야하는 부분은 DrawManager를 통해 직접 호출하여 그리도록 구현(뱀의 좌표를 바로 보내줄수잇기떄문)

그외에 이동속도 / 방향전환의 텀 / 꼬리갯수 등 뱀과 직접 관련한 부분들 관리



**MapDraw.cpp MapDraw.h**

블록을 그리는 함수를 직접 구현하여둔 클래스. 
필요한곳에서 DrawManager를 통해 호출하여 사용



실제 플레이 영상
https://youtu.be/U6QiowpcfV0

다운로드
https://github.com/tjdwlgns7749/SnakeGame
