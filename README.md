# SnakeGame

C++ 을 활용해서 만든 오목게임 입니다.

**클래스 구성**

![오목 클래스](https://user-images.githubusercontent.com/82795868/206744899-30c97324-5a8c-4ab3-8e74-e1248a625a97.png)

**소스.cpp**

PlayerManager를 객체로 1개 생성하여 게임시작


**Block.cpp / Block.h**
![이미지1](https://user-images.githubusercontent.com/82795868/206752721-e1676071-7545-4435-8e7d-d8f2ae1c6259.png)

Player를 멤버로 가지고 있으며 
맵의 크기 턴을 가지고 게임의 전체적인 흐름과 
MapDraw에 구현한 함수들을 호출하여 
메뉴와 게임화면을 그리도록 관리하고있다. 



**Player.cpp Player.h**

실제로 커서,돌모양,돌의좌표와 순서 등 게임의 진행과 리플레이 저장과 실행에 필요한 데이터를 저장하고 
게임에 필요한 승리체크와 메모리관리 등 주요기능 구현하고 잇다.



**MapDraw.cpp MapDraw.h**

바둑판과 커서 그리고 놓여진 바둑돌을 그리는 함수를 직접 구현하여둔 클래스. 
필요한곳에서 DrawManager를 통해 호출하여 사용



실제 플레이 영상
https://youtu.be/U6QiowpcfV0

다운로드
http://naver.me/IGGK5iiP
