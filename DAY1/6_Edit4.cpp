// ���ϴ� ���� �и��ϴ� 2���� ���
// 1. ���ϴ� ���� �����Լ���    : template method pattern - edit2.cpp
// 2. ���ϴ� ���� �ٸ� Ŭ������ : strategy pattern        - edit3.cpp


// #1. template method
// => ��ӱ���� ����
// => �����Լ� override �� ���ؼ� ���ϴ� �� ��ü
// Ư¡ 1. NumEdit �� Validation ��å�� ����
//        �ٸ� Ŭ������ NumEdit �� Validation ��å ������.
// Ư¡ 2. NumEdit �� ��å�� ������ �̹Ƿ� �ٸ� ��å���� ��ü �ȵ�.

// Ư¡ 3. ��å �Լ��� ��� �Լ��� �����ǹǷ� private ����� ���� ����

// #2. strategy
// Ư¡ 1. Edit �� Validation ��å�� �и�.. 
//        �ٸ� Ŭ������ LimitDigitValidator ��밡��
// 
// Ư¡ 2. ����ð��� ��å ��ü�� �����ϴ�.
//		  e.set_validator(&�ٸ���å);

// Ư¡ 3. ��å �Լ��� ������ Ŭ������ ���� �ǹǷ�
//         private ����� ���� �ȵ�. �Լ� ���ڵ����� ����Ÿ �����ؾ� �Ѵ�


// ���������� ��������  Shape/Rect �� draw �� draw_imp ����
// 1. Rect �� �׸��� ����� Rect �� �˸� �ǰ�
// 2. Rect �� �׸��� ����� ����ð��� ��ü�� �ʿ䵵 ����.
// strategy ���� template method �� ����!!! - private ���� ����.
