# 클린코드

### 나쁜 코드

- 나쁜 코드를 짜는 이유
  - 제대로 짤 시간이 없다고 생각해서
  - 급해서
  - 서두르느라
  - 빨리 끝내고 밀린 업무로 돌아가야해서
  - 나중에 손보겠다고 생각

#### 하지만, 나중은 결코 오지 않는다. (르블랑의 법칙)

> 르블랑의 법칙: Never == Later



</br>



### 나쁜 코드로 치르는 대가

> 1. 개발 속도를 크게 떨어뜨림
> 2. 코드를 고칠 때마다 엉뚱한 곳에 문제가 생김
> 3. 팀 생산성이 떨어짐



#### 원대한 재설계의 꿈

- 나쁜코드로 인해 생산성이 떨어짐으로써, 재설계 시작
  - 재설계를 하는 경우, 기존 시스템의 기능을 모두 제공해야함
  - 하지만 재설계하는 데 시간이 오래걸릴 뿐만 아니라 엉망인 경우도 있음



#### 그러므로, 시간을 들여 깨끗한 코드를 만드는 노력이 비용을 절감하는 방법일 뿐만 아니라 전문가로서 살아남는 길이다.



</br>



#### 태도

- 좋은 코드가 한순간에 나쁜 코드로 전락하는 이유
  - [나쁜 코드를 짜는 이유와 비슷함](https://github.com/yeahsilver/Clean_Code/blob/master/chapter1/README.md#나쁜-코드)
- 좋은 코드를 사수하는 일은 바로 프로그래머들의 책임이다.
  - 이유) 프로그래머들은 프로젝트를 계획하는 과정에 깊숙히 관여함



</br>



#### 원초적 난제

- `프로그래머들은 나쁜 코드가 업무 속도를 늦춘다는 사실을 알고있다. 그런데 왜 나쁜코드를 양산할까?`

  > answer) 빨리 가기 위해 시간을 들이지 않는다.



###### 하지만 나쁜 코드를 양산하면 기한을 맞추지 못한다.

#### 그러므로, 기한을 맞추기 위해서는 언제나 코드를 최대한 깨끗하게 유지하는 습관을 가져야한다.



#### 깨끗한 코드라는 예술?

- `깨끗한 코드를 어떻게 작성할까?`

  > 청결이라는 감각을 활용하여 여러가지 기법들을 적용하는 절제와 규율이 필요하다.



- `코드 감각이 있으면?`

  > 1. 좋은 코드와 나쁜 코드를 구분할 수 있다.
  > 2. 절제와 규율을 적용하여 나쁜 코드를 좋은 코드로 바꾸는 전략을 파악할 수 있다.
  > 3. 나쁜 모듈을 좋은 모듈로 개선할 방안을 떠올린 후, 이동 경로를 계획한다.



</br>



-----------



</br>



## 의미있는 이름

- ### 의도를 분명히 밝혀라

  > 단순히 이름만 고쳤는데도 함수가 하는 일에 대해 이해하기 쉬워진다.

  ```java
  int d; // 의도를 분명히 드러내지 못하는 변수명
  int elapseTimeInDays; // 의도를 분명히 드러내는 변수명
  ```

------



- ### 그릇된 정보를 피하라

  > 그릇된 단서는 코드의 의미를 흐린다.

  ```java
  int hp; // hypotenuse의 약어. 하지만 오해의 소지가 있음.
  class Account{} // Account라는 class라는 것이 분명함 
  ```

------



- ### 의미 있게 구분하라

  > 읽는 사람이 차이를 알도록 이름을 짓는다.

  ```java
  // 의미를 구별하기 힘든 경우 (= 어떤 기능을 하는지를 정확히 추측하기가 힘듦.)
  moneyAccount();
  money();
  
  // 의미를 구별하기 쉬운 경우
  getActiveAccount();
  getActiveAccounts();
  ```

------



- ### 발음하기 쉬운 이름을 사용하라

  > 발음하기 쉬운 단어를 사용함으로써 가독성을 높인다.

  ```java
  // 발음하기 어려운 경우
  class DtaRcrd102{
    private Date genmdhms;
    private Date modymdhms;
    private final String pszqint = "102";
  }
  
  // 발음하기 쉬운 경우
  class Customer{
    private Date generationTimestamp;
    private Date modificationTimestamp;
    private final String recordId = "102";
  }
  ```

------



- ### 검색하기 쉬운 이름을 사용하라

  > 문자 하나를 사용하는 이름과 상수는 텍스트 코드에서 쉽게 눈에 띄지 않는다.

  ```java
  // 검색하기 어려운 이름 (= 검색하면 많은 요소들이 나오는 경우)
  int e;
  
  // 검색하기 쉬운 이름
  int realDaysPerIdealDay = 4;
  ```

------



- ### 인코딩을 피하라

  - #### 헝가리식 표기법

    > 컴파일러가 타입을 점검하지 않을 경우에는 변수명에 타입명을 적어주었다.

    ```java
    PhoneNumber phoneString; // 헝가리식 표기법
    ```

  - #### 멤버 변수 접두어

    > 클래스와 함수는 접두어가 필요 없을 정도로 작아야한다. 그러므로 멤버 변수 접두어를 붙일 필요가 없다.

    ```java
    // 멤버 변수 접두어를 사용한 경우
    public class Part{
    private String m_dsc; // 설명 문자열
    void setName(String name){
      m_dsc = name;
    }
    }
    
    // 멤버 변수 접두어를 사용하지 않은 경우
    public class Part{
    String description;
    void setDescription(String description){
      this.description = description;
    }
    }
    ```

   

  - #### 인터페이스 클래스와 구현 클래스

    > 인터페이스 이름은 접두어를 붙이지 않는 것이 좋다.
    >
    > 이유) 주의를 흐트리고 과도한 정보를 제공

   

------



- ### 자신의 기억력을 자랑하지 마라

  > 자신의 능력을 좋은 방향으로 사용하여 남들이 이해하는 코드를 제공해 주는 것이 좋다.

------



- ### 클래스 이름

  > 클래스 이름과 객체 이름은 명사나 명사구가 적합하다.

  ```java
  // 적합하지 않은 클래스 이름
  Class Data(){};
  
  // 적합한 클래스 이름
  Class Customer(){};
  ```

------



- ### 메소드 이름

  > 메소드 이름은 동사나 동사구가 적합하다
  >
  > 생성자를 중복정의할 때는 정적 팩토리 메소드를 사용한다.

  ```java
  // 적합한 메소드 이름
  postPayment();
  deletePage();
  ```

  ```java
  // 정적 팩토리 메소드를 사용하지 않은 경우
  Complex fulcrumPoint = new Complex(23.0);
    
  // 정적 팩토리 메소드를 사용한 경우
  Complex fulcrumPoint = Complex.FromRealNumber(23.0);
  ```



------



- ### 기발한 이름은 피하라

  > 기발한 이름은 의도를 분명하고 솔직하게 표현할 수 없다.

  ```java
  // 기발한 이름
  whack();
  eatMyShort();
  
  // 명료한 이름
  kill();
  abort();
  ```

------

 

- ### 한 개념에 한 단어를 사용하라

  > 메소드와 메소드 이름은 독자적이고 일관적이여야 한다.

  ```java
  /* 
  같은 의미를 내포하는 변수명. 
  manager나 controller 둘 중 하나를 선택해서 사용해야함. 
  */
  
  DeviceManager;
  DeviceController;
  ```

------



- ### 말장난을 하지 마라

  > 한 단어를 두 가지 목적으로 사용하지 않아야 한다.

  ```java
  // 더하기를 하는 메소드
  int add(){};
  
  /* 
  값을 넣어주는 메소드
  이때 메소드를 add라고 정의하면 해당 코드가 어떤 의미를 가지는지 이해하기 힘듦.
  */
  int insert(){};
  ```

------



- ### 해법 영역에서 가져온 이름을 사용하라

  > 기술 개념에는 기술이름이 가장 적합하듯, 영역에 맞게 이름을 사용해야한다.

 

------



- ### 문제영역에서 가져온 이름을 사용하라

  > 적절한 프로그래머 용어가 없다면 문제 영역에서 이름을 가져온다.



------



- ### 의미 있는 맥락을 추가하라

  > 맥락을 개선하면 함수를 쪼개기가 쉬워지므로 알고리즘도 좀 더 명확해진다.

  ```java
  // 맥락이 분명하지 않은 변수
  private void printGuessStatistics(char candidate, int count){
    if (count == 0){
      number = "no";
    } else if (count == 1) {
      number = "1";
    }
    
    String guessMessage = String.format("There %s", verb);
    print(guessMessage);
  }
  
  // 맥락이 분명한 변수
  
  private class GuessStaticsMessage{
    public String make(char candidate, int count){
      createPluralDependenMessageParts(count);
      return String.format(
      "There %s", verb);
    }
    
    private void createPluralDependenMessageParts(int count){
      if(count == 0){
        thereAreNoLetters();
      } else if(count == 1){
        thereIsOneLetter();
    	} else {
        thereAreManyLetters(count);
      }
  }
  ```



------



- ### 불필요한 맥락을 없애라

  > 일반적으로 짧은 이름이 긴 이름보다 좋지만, 의미가 분명한 경우가 아니라면이름에 불필요한 맥락을 추가할 필요가 없다.

  ```java
  // 불필요한 맥락을 가진 변수명
  int AccountAddress;
  int GSDAccountAddress;
  
  // 불필요한 맥락을 가지지 않은 변수명
  int postalAddress;
  int MACUrl;
  ```



</br>



-----



</br>



## 함수

- ### 작게 만들어라

  > 함수를 만드는 첫째 규칙은 '작게', 두번째 규칙은 '더 작게'이다.

  - ##### 블록과 들여쓰기

    > if문 / else문 / while문 등에 들어가는 블록은 한 줄이여아 한다.
    >
    > 중첩 구조가 생길만큼 함수가 커져서는 안된다.



------



- ### 한가지만 해라

  ###### 함수는 한 가지를 해야한다. 그 한가지를 잘 해야 한다. 그 한가지만을 해야한다.

  > 함수를 만드는 이유는 큰 개념을 다음 추상화 수준에서 여러 단계로 나눠 수행하기 위해서이기에 함수는 한 가지의 역할만을 수행해야한다.



------



- ### 함수 당 추상화 수준은 하나로

  > 함수 내 모든 문장의 추상화 수준이 동일해야 한다.

  - ##### 위에서 아래로 코드 읽기: 내려가기 규칙

    > 코드는 위에서 아래로 이야기처럼 읽혀야 좋다.
    >
    > 핵심은 짧으면서도 '한 가지'만 하는 함수다.



------



- ### Switch 문

  > 상속 관계로 숨긴 후에는 절대로 다른 코드에 노출하지 않게 만들어 놓는다.



------



- ### 서술적인 이름을 사용하라

  ###### 좋은 이름이 주는 가치는 아무리 강조해도 지나치지 않다.

  ###### 길고 서술적이 이름 > 길고 서술적인 주석

  > 한 가지만 하는 작은 함수에 좋은 이름을 붙인다면 이미 절반은 성공
  >
  > 함수가 작고 단순할수록 서술적인 이름을 고리기도 쉬워진다.



------



- ### 함수 인수

  - ##### 많이 쓰는 단항 형식

    > 1. 인수에 질문을 던지는 경우 사용
    > 2. 인수를 뭔가로 변환해 결과를 반환하는 경우 사용
    > 3. 이벤트를 사용하는 경우

    ```
    boolean fileExists("MyFile") // 첫 번쨰 경우
    InputStream fileOpen("MyFile") // 두 번째 경우
    passwordAttemptFailedNtimes(int attempts) // 세 번째 경우
    ```

  - ##### 플래그 인수

    > 플래그 인수를 사용하는 것은 함수가 여러가지 일을 처리하는 것과 같음

  - ##### 이항 함수

    > 인수가 1개인 함수보다 이해하기 어렵다. 그러므로 가능하면 단항 함수로 바꾸도록 애써야 한다.

  - ##### 삼항 함수

    > 인수가 3개인 함수는 인수가 2개인 함수보다 훨씬 더 이해하기 어렵다. 그래서 삼항 함수를 만들 때는 신중하게 고려해야한다.

   

  - ##### 인수 객체

    > 인수가 2~3개 필요하다면 일부를 독자적인 클래스 변수로 선언할 가능성을 짚어 본다.

    ```
    Circle makeCircle(double x, double y, double radius);
    Circle makeCircle(Point center, double radius); // 클래스변수로 선언
    ```

  - ##### 인수 목록

    > 가변 인수 전부를 동등하게 취급하면 List형 인수 하나로 취급할 수 있다.

    ```
    String.format("%s worked %.2f hours", name, hours);
    ```

  - ##### 동사와 키워드

    > 단항 함수는 함수와 인수가 동사 / 명사 쌍을 이뤄야 한다.

    ```
    writeField(name)
    ```

    > 함수 이름에 키워드를 추가하면 인수 순서를 기억할 필요가 없다.

    ```
    assertExpectedEqualsActual(expected, actual)
    ```



------



- ### 부수 효과를 일으키지 마라

  > 부수 효과로 특정 기능이 숨겨진 경우에는 더더욱 혼란이 커진다.

  - ##### 출력 인수

    > 일반적으로 우리는 인수를 함수 입력으로 해석하기에, 출력 인수는 피해야 한다.



------



- ### 명령과 조회를 분리하라

  > 함수는 뭔가를 수행하거나 뭔가에 답을 하거나 둘 중 하나의 기능만을 수행해야 한다

  - ##### 리팩터링 전 코드

    > username이 unclebob으로 설정되어있는지, username을 unclebob으로 설정하는 것인지 모호함.

    ```
    if(set("username", "unclebob"))....
    ```

  - ##### 리펙터링 후 코드

    > 명령과 조회를 분리해 혼란을 없앰

    ```
    if(attributeExists("username")){
    	setAttribute("username", "unclebob");
    }
    ```



------



- ### 오류 코드보다 예외를 사용하라

  > 오류 코드 대신 예외를 사용하면 오류 처리 코드가 원래 코드에서 분리되므로 코드가 깔끔해진다.
  >
  > 재컴파일 / 재배치 없이도 새 예외 클래스를 추가할 수 있다.

  ```
  try{
  	deletePage(page);
  } catch(Exception e){
  	logger.log(e.getMessage());
  }
  ```

  - ##### Try/Catch 블록 뽑아내기

    > try/catch문은 코드 구조에 혼란을 일으키며, 정상 동작과 오류 처리 동작을 뒤섞기에 별도의 함수로 뽑아내는 편이 좋다.

    ```
    public void delete(Page page){
    	try{
    		deletePage(page);
    	}	catch(Exception e) {
    		logError(e);
    	}
    }
    ```



------



- ### 반복하지 마라

  > 중복을 없애면 가독성이 크게 높아진다.



------



- ### 구조적 프로그래밍

  > 모든 함수와 함수 내 모든 블록에 입구과 출구가 하나마나 존재해야한다.
  >
  > 하지만 함수가 작다면 위 규칙은 이익을 제공해주기 않기에, return break, continue 등을 여러 차례 사용해도 괜찮다.



------



- ### 함수를 어떻게 짜죠?

  1. 생각을 기록
  2. 코드 다듬기
  3. 함수 생성
  4. 이름 변환
  5. 중복 제거



</br>



-------



</br>



## 형식 맞추기

- ### 형식을 맞추는 목적

  > 코드 형식은 의사소통의 일환이다.
  >
  > 오늘 구현한 코드의 가독성은 앞으로 바뀔 코드의 품질에 지대한 영향을 미친다.



------



- ### 적절한 행 길이를 유지하라

  > 500줄을 넘지 않고 대부분 200줄 정도인 파일로도 커다란 시스템을 구축할 수 있다.
  >
  > 일반적으로 큰 파일보다 작은 파일이 이해하기 쉽다.

  - #### 신문 기사처럼 작성하라

    > 이름은 간단하면서 설명이 가능하게 지어라.
    >
    > 아래로 내려갈 수록 세세하게 묘사한다.
    >
    > 신문의 기사는 대부분 아주 짧다. 그러니 코드도 짧게 작성하라!

  - #### 개념은 빈 행으로 분리하라

    > 생각 사이에는 빈 행을 넣어 분리해야 마땅하다.
    >
    > 빈 행은 새로운 개념을 시작한다는 시각적 단서가 될 수 있다.
    >
    > 빈 행은 가독성을 높인다.

  - #### 세로 밀집도

    > 서로 밀접한 코드 행은 세로로 가까이 놓여야 한다.

    ###### 세로 밀집도 구현 전

    ```
    public class ReporterConfig{
    	/*
    	* 리포터 리스너의 클래스 이름
    	*/
    	private String m_className;
    	
    	/*
    	*	리포터 리스너의 속성
    	*/
    	private List<property> m_properties = new ArrayList<Property>();
    	public void addProperty(Property property){
    		m_properties.add(property);
    	}
    }
    ```

    ###### 세로 밀집도 구현 후

    ```
    public class ReporterConfig{
    	private String m_className;
    	private List<property> m_properties = new ArrayList<Property>();
    	
    	public void addProperty(Property property){
    		m_properties.add(property);
    	}
    }
    ```

  - #### 수직거리

    > 변수는 사용하는 위치에 최대한 가까이 선언한다.

    ```
    private satic void readPreferences(){
    	InputStream is = null;
    	try{
    		is =. ew FileInputStream(getPreferenceFile());
    		setPreferences().load(is);
    	} catch (IOException e){
    		try{
    			if(is != null) is.close();
    		} catch (IOException e1){
    		}
    	}
    }
    ```

    > 인스턴스 변수는 클래스의 맨 처음에 선언한다. (c++에서는 맨 마지막에 선언 (=가위규칙))

    ```
    private String fName;
    
    private vector<Test> fTests = new Vector<Test>(10);
    public testSuite(){
    ...
    }
    ```

    > 한 함수가 다른 함수를 호출한다면 두 함수는 세로로 가까이 배치한다.
    >
    > 개념적인 친화도거 높을수록 코드를 가까이 배치한다.

    ```
    public class Assert{
    	static public void assertTrue(String message, boolean condition){
    		if(!condition)
    			fail(meddage);
    	}
    	static public void assertTrue(boolean condition){
    		assertTrue(null, condition);
    	}
    }
    ```

  - #### 세로 순서

    > 함수 호출 종속성은 아래 방향으로 유지한다.
    >
    > 가장 중요한 개념을 먼저 표현한다.

- ### 가로 형식 맞추기

  > 프로그래머는 명백하게 짧은 행을 선호한다.

  - #### 가로 공백도와 밀집도

    > 공백을 사용해 밀접한 개념과 느슨한 개념을 표현한다.

    ```
    private void measureLine(String line){
    	lineCount++;
    	int lineSize = line.length();
    	totalChars += lineSize;
    	lineWidthHistogram.addLine(lineSize, lineCount);
    	recordWidestLine(lineSize);
    }
    ```

    ```
    public class Quadratic {
    	public static double root1(double a, double b, double c){
    		double determinant = determinant(a,b,c);
    	}
    }
    ```

  - #### 가로 정렬

    > 정렬은 엉뚱한 부분을 강조하기에 진짜 의도가 가려지는 경우가 많다.

   

  - #### 들여쓰기

    > 범위로 이루어진 계층을 표현하기 위해 코드를 들여쓴다. (while / if문 포함)

  - #### 가짜 범위

    > while문 끝에 세미콜론을 붙히는 경우 => 괄호로 감싼다.

    ```
    while(dis.read(buf, 0, reaBufferSize) != 1)
    ;
    ```