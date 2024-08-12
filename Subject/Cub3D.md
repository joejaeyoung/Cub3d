>My first RayCaster with miniLibX

# Summary
This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you’ll have to find your way.

# Goals
- This project’s objectives are similar to all this first year’s objectives: Rigor, use of C, use of basic algorithms, information research etc.
- 이 프로젝트의 목표는 첫해의 모든 목표와 유사합니다 : 엄격성, C 사용, 기본 알고리즘 사용, 정보 연구 등입니다.

- As a graphic design project, cub3D will enable you to improve your skills in these areas: windows, colors, events, fill shapes, etc.
- 그래픽 디자인 프로젝트로서 cub3D는 창, 색상, 이벤트, 모양 채우기 등의 영역에서 기술을 향상시킬 수 잇습니다.

- To conclude cub3D is a remarkable playground to explore the playful practical applications of mathematics without having to understand the specifics.
- 결론적으로 cub3D는 세부적인 내용을 이해하지 않고도 수학의 재미있는 실제 응용을 탐구할 수 있는 놀라운 놀이터입니다.

- With the help of the numerous documents available on the internet, you will use mathematics as a tool to create elegant and efficient algorithms.
- 인터넷에서 제공되는 수많은 문서의 도움을 받아 수학을 도구로 사용하여 우아하고 효율적인 알고리즘을 만들 수 있습니다.

- 이 프로젝트를 시작하기 전에 원본 게임을 테스트하는 것이 좋습니다:
- http://users.atw.hu/wolf3d/

# Common Instructions
- To turn in bonuses to your project, you must include a rule bonus to your Makefile, which will add all the various headers, librairies or functions that are forbidden on the main part of the project. 
- 프로젝트에 보너스를 추가하려면 프로젝트의 주요 부분에 금지된 헤더, 라이브러리 또는 함수를 모두 추가하는 규칙 bonus를 makefile에 포함해야 합니다.

- Bonuses must be in a different file _bonus.{c/h} if the subject does not specify anything else.
- 보너스는 주제에서 다른 것을 지정하지 않은 경우 다른 파일 `_bonus.{c/h}`에 있어야 합니다.

- Mandatory and bonus part evaluation is done separately.
- 필수 부분과 보너스 부분 평가는 별도로 진행됩니다.

- If your project allows you to use your libft, you must copy its sources and its associated Makefile in a libft folder with its associated Makefile. 
- 프로젝트에서 라이브러리프트 사용을 허용하는 경우 라이브러리프트 폴더에 소스 및 관련 메이크파일을 관련 메이크파일이 있는 라이브러리프트 폴더에 복사해야 합니다. 

- Your project’s Makefile must compile the library by using its Makefile, then compile the project.
- 프로젝트의 메이크파일은 해당 메이크파일을 사용하여 라이브러리를 컴파일한 다음 프로젝트를 컴파일해야 합니다.

# Mandatory part - cub3D
- Program name : cub3D
- Trun in files : All your files
- Makefile : all, clean, fclean, re, bonus
- Arguments : a map in format `*.cub`
- External functs
	- open, close, read, write
	- printf, perror, strerror
	- malloc, free
	- exit
	- All functions of the math library (-lm)
	- All functions of the MinilibX
- Libft authorized : Yes
- Description :
	- You must create a “realistic” 3D graphical representation of the inside of a maze from a first-person perspective. You have to create this representation using the Ray-Casting principles mentioned earlier.
	- 1인칭 시점으로 미로 내부를 "사실적인" 3D 그래픽으로 표현해야 합니다. 앞서 언급한 레이캐스팅 원리를 사용하여 이 표현을 만들어야 합니다.


# 제약 조건

- miniLibX를 반드시 사용해야 합니다.

- The management of your window must remain smooth : changing to another window, minimizing, etc.
- 다른 창으로 변경, 최소화 등 창 관리가 원할하게 이루어져야 합니다.

 - Display different wall textures (the choice is yours) that vary depending on which side the wall is facing (North, South, East, West)
 - 벽이 향하는 방향(북쪽, 남쪽, 동쪽, 서쪽)에 따라 다른 벽 텍스처(선택은 사용자의 몫)를 표시합니다.

- Your program must be able to set the floor and ceiling colors to two different ones.
- 프로그램은 바닥과 천장 색상을 서로 다른 두 가지 색상으로 설정할 수 있어야 합니다.

- The program displays the image in a window and respects the following rules:
- 프로그램은 이미지를 창에 표시하며 다음 규칙을 준수합니다:
- 키보드의 왼쪽 및 오른쪽 화살표 키를 사용하여 미로에서 왼쪽과 오른쪽을 볼 수 있어야 합니다.
- W, A, S, D 키는 미로에서 시점을 이동할 수 있어야 합니다.
- ESC 키를 누르면 창이 닫히고 프로그램이 깨끗하게 종료되어야 합니다.
- 창 프레임의 빨간색 십자가를 클릭하면 창을 닫고 프로그램을 깨끗하게 종료해야 합니다.
- miniLibX의 이미지 사용을 적극 권장합니다.

- 프로그램은 첫 번째 인수로 확장자가 `.cub`인 장면 설정 파일을 가져와야 합니다.
- 맵은 가능한 6개의 문자로만 구성되어야 합니다 :
	- 0 : 빈공간
	- 1 : 벽
	- N, S E or W : 플레이어의 시작 위치 및 스폰 방향
	- 지도는 벽으로 둘러싸여 있어야 하며, 그렇지 않은 경우 프로그램에서 오류를 반환해야 합니다.
	- 지도 콘텐츠를 제외한 각 유형의 요소는 하나 이상의 빈 줄로 구분할 수 있습니다.
	- 항상 마지막에 위치해야 하는 지도 콘텐츠를 제외한 각 유형의 요소는 파일에서 원하는 순서로 설정할 수 있습니다.
	- 지도를 제외한 각 요소의 각 정보 유형은 하나 이상의 공백으로 구분할 수 있습니다.
	- 지도는 파일에서 보이는 그대로 파싱되어야 합니다. 
	- 스페이스는 지도의 유효한 부분이며 사용자가 처리할 수 있습니다. 
	- 모든 종류의 지도를 구문 분석할 수 있어야 합니다,
	- 지도의 규칙을 준수하기만 하면 됩니다.

- 각 요소(지도 제외)의 첫 번째 정보는 유형 식별자(한두 개의 문자로 구성)이며 그 다음에는 각 객체에 대한 모든 구체적인 정보가 다음과 같은 엄격한 순서로 나열됩니다.
- ∗ 북쪽 텍스처:
NO ./path_to_the_north_texture
- 식별자 NO
- 북쪽 텍스처로 가는 경로
∗ 남쪽 텍스처:
SO ./path_to_the_south_texture
- 식별자 SO
- 남쪽 텍스처로 가는 경로
∗ 서쪽 텍스처:
WE ./path_to_the_west_texture
- 식별자 WE
- 서쪽 텍스처로 가는 경로
∗ 동쪽 텍스처:
EA ./path_to_the_east_texture
- 식별자 EA
- 동쪽 텍스처로 가는 경로
∗ 바닥 색:
F 220,100,0
- 식별자 F
- 범위 [0,255]의 R,G,B 색상: 0, 255, 255
천장 색상:
C 225,30,0
- 식별자: C
- 범위 [0,255]의 R,G,B 색상: 0, 255, 255

파일에서 어떤 종류의 잘못된 구성이 발견되면, 프로그램이 올바르게 종료되고, error\n을 반환한 후 원하는 오류 메시지를 반환해야 합니다.
