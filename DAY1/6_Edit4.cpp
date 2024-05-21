// 변하는 것을 분리하는 2가지 기술
// 1. 변하는 것을 가상함수로    : template method pattern - edit2.cpp
// 2. 변하는 것을 다른 클래스로 : strategy pattern        - edit3.cpp


// #1. template method
// => 상속기반의 패턴
// => 가상함수 override 를 통해서 변하는 것 교체
// 특징 1. NumEdit 가 Validation 정책을 소유
//        다른 클래스가 NumEdit 의 Validation 정책 사용못함.
// 특징 2. NumEdit 가 정책의 소유자 이므로 다른 정책으로 교체 안됨.

// 특징 3. 정책 함수가 멤버 함수로 구현되므로 private 멤버에 접근 가능

// #2. strategy
// 특징 1. Edit 와 Validation 정책이 분리.. 
//        다른 클래스도 LimitDigitValidator 사용가능
// 
// 특징 2. 실행시간에 정책 교체가 가능하다.
//		  e.set_validator(&다른정책);

// 특징 3. 정책 함수가 별도의 클래스로 제공 되므로
//         private 멤버에 접근 안됨. 함수 인자등으로 데이타 전달해야 한다


// 도형편집기 예제에서  Shape/Rect 의 draw 와 draw_imp 에서
// 1. Rect 를 그리는 방법은 Rect 만 알면 되고
// 2. Rect 를 그리는 방법은 실행시간에 교체될 필요도 없다.
// strategy 보다 template method 가 좋다!!! - private 접근 가능.
