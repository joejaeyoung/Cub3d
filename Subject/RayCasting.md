- 레이캐스팅은 2차원 맵에서 3차원의 원근감을 구현하기 위한 렌더링 기술이다.

## 기본 적인 원리
- 화면의 x축으로 모든 픽셀마다 카메라가 바라보고 있는 방향으로 광선을 투사한다.
  그리고 벽을 만나면 해당 벽까지의 거리를 얻는다.
  - 벽까지의 거리가 멀면 가로 1픽셀 짜리 짧은 세로줄을 해당 x위치에 그린다.
  - 벽까지의 거리가 가까우면 가로 1픽셀짜리 긴 세로줄을 해당 x위치에 그린다.

이를 화면 가로 사이즈만큼 반복하여 모든 벽면을 그리면, 2D 공간임에도 3D 같은 사실적인 원근감을 얻을 수 있다.

이러한 기법의 장점은 계산 방법에서 알 수 있듯, 모든 수직선에 대해서만 계산을 하면 되기 때문에 렌더링 속도가 매우 빠르다.
게다가 오로지 정수만으로도 계산이 가능하기에 실수 계산이 전혀 필요없다.

## 카메라 평면
레이캐스팅은 2D 공간에서 이루어지기에, 1차원 벡터만을 이용한다.
레이캐스팅에서는 광선이 항상 이 카메라 평면을 통과하여, 평면에 수직 방향으로 투사된다.

## 특징
레이캐스팅은 적은 연산만으로도 3차원처럼 보이는 공간을 구현할 수 있는, semi-3D 기술이다.
하지만 장면의 반사나 그림자 효과를 지원하는 레이 트레이싱과 비교하면, 재현력이 다소 떨어진다.

#### 레이캐스팅의 한계
- 모든 벽은 수직이어야 한다.
- 바닥은 평평해야 한다.
- 벽은 동일한 크기의 큐브로 이루어져야 한다.

## 원리
