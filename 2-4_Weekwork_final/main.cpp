//#include <iostream>
//#include <vector>
//#include <map>
//#include <algorithm>
//
//using namespace std;
//
///*
// [1] Movie
// - 문제에서 다루는 최소 단위 데이터
// - "영화"라는 개념을 제목(title)과 평점(rating)으로 단순화
// - 값 자체가 의미이므로 struct 사용
//*/
//struct Movie {
//    string title;
//    double rating;
//};
//
///*
// [2] MovieProcessor (추상화된 처리 전략)
// - 영화 목록을 "어떻게 처리할지"에 대한 공통 규약
// - MovieManager는 구체적인 처리 방식(정렬/필터 등)을 몰라도 됨
// - process 하나만 강제 → 다형성 기반 확장
//*/
//class MovieProcessor {
//public:
//    virtual void process(vector<Movie>& movies) = 0;
//    virtual ~MovieProcessor() = default;
//};
//
///*
// [3] MovieManager (데이터 소유자 / 컨텍스트)
// - 영화 데이터를 직접 관리하는 클래스
// - 무엇을 할지는 알고 있지만, 어떻게 처리할지는 모름
// - 처리 로직은 MovieProcessor에게 위임
//*/
//class MovieManager {
//private:
//    // 영화 목록 (순회, 정렬, 필터의 대상)
//    vector<Movie> movies;
//
//    // 제목 기반 빠른 검색을 위한 인덱스
//    map<string, double> movieMap;
//
//public:
//    // 초기 데이터 구성 책임
//    MovieManager() {
//        movies = {
//            {"Inception", 9.0},
//            {"Interstellar", 8.6},
//            {"The Dark Knight", 9.1},
//            {"Memento", 8.4}
//        };
//
//        // 검색을 빠르게 하기 위해 보조 자료구조 구성
//        for (const auto& movie : movies) {
//            movieMap[movie.title] = movie.rating;
//        }
//    }
//
//    // 전체 영화 목록 출력 (가장 기본 기능)
//    void printMovies() {
//        cout << "영화 목록:\n";
//        for (const auto& movie : movies) {
//            cout << "제목: " << movie.title
//                << ", 평점: " << movie.rating << "\n";
//        }
//    }
//
//    // 제목으로 영화 검색 (정렬/필터와 무관한 기능)
//    void findMovie(const string& title) {
//        auto it = movieMap.find(title);
//        if (it != movieMap.end()) {
//            cout << "영화 제목: " << it->first
//                << ", 평점: " << it->second << "\n";
//        }
//        else {
//            cout << "해당 영화는 목록에 없습니다.\n";
//        }
//    }
//
//    /*
//     [핵심 확장 포인트]
//     - 어떤 Processor가 들어오든 상관없이 실행만 담당
//     - MovieManager는 알고리즘 변경에 닫혀 있음(OCP)
//    */
//    void processMovies(MovieProcessor& processor) {
//        processor.process(movies);
//    }
//};
//
///*
// [4] RatingSorter (정렬 전략)
// - "영화를 평점 기준으로 정렬한다"는 요구사항을 담당
// - MovieProcessor 인터페이스를 구현하여 전략으로 동작
//*/
//class RatingSorter : public MovieProcessor {
//public:
//    void process(vector<Movie>& movies) override {
//        // 정렬 규칙을 외부로 드러내기 위해 static 비교 함수 사용
//        sort(movies.begin(), movies.end(), compareMovies);
//
//        cout << "평점 기준 정렬된 영화 목록:\n";
//        for (const auto& movie : movies) {
//            cout << "제목: " << movie.title
//                << ", 평점: " << movie.rating << "\n";
//        }
//    }
//
//    // sort에 전달될 비교 규칙 (내림차순)
//    static bool compareMovies(const Movie& a, const Movie& b) {
//        return a.rating > b.rating;
//    }
//};
//
///*
// [5] RatingFilter (필터 전략)
// - "특정 평점 이상만 출력"이라는 또 다른 처리 요구 담당
// - 내부 상태(minRating)를 가지는 전략
//*/
//class RatingFilter : public MovieProcessor {
//private:
//    double minRating;
//
//public:
//    explicit RatingFilter(double minRating)
//        : minRating(minRating) {
//    }
//
//    void process(vector<Movie>& movies) override {
//        cout << "평점 " << minRating << " 이상인 영화 목록:\n";
//        for (const auto& movie : movies) {
//            if (movie.rating >= minRating) {
//                cout << "제목: " << movie.title
//                    << ", 평점: " << movie.rating << "\n";
//            }
//        }
//    }
//};
//
///*
// [6] 실행 흐름
// - MovieManager는 데이터 관리
// - Processor들은 처리 방식만 담당
// - 실행 시점에 어떤 전략을 쓸지 선택
//*/
//int main() {
//    MovieManager manager;
//
//    cout << "1. 영화 목록 출력\n";
//    manager.printMovies();
//
//    cout << "\n2. 영화 검색 (예: Interstellar)\n";
//    manager.findMovie("Interstellar");
//
//    cout << "\n3. 평점 기준 정렬 및 출력\n";
//    RatingSorter sorter;
//    manager.processMovies(sorter);
//
//    cout << "\n4. 평점 8.5 이상인 영화 필터링 및 출력\n";
//    RatingFilter filter(8.5);
//    manager.processMovies(filter);
//
//    return 0;
//}
