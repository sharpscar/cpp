#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt{
    private:
        enum{Lbs_per_stn = 14}; //스톤당 파운드수
        int stone;
        double pds_left;
        double pounds;
    public:
        Stonewt(double lbs);    //double형 파운드를 위한 생성자
        Stonewt(int stn, double lbs);
        Stonewt();
        ~Stonewt();
        void show_lbs() const;  //파운드형식
        void show_stn() const;  // 스톤과 파운드 조합형식

        // 변환함수들
        operator int() const;
        operator double() const;

    };

#endif