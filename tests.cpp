#include <gtest/gtest.h>
#include <random>
#include "mymap.h"


TEST(mymap, one) {
mymap<int, int> map;
int arr[] = {2, 1, 3};
for (int i = 0; i < 3; i++) {
map.put(arr[i], arr[i]);
}

EXPECT_EQ(map.Size(), 3);
for (int i = 0; i < 3; i++) {
EXPECT_TRUE(map.contains(arr[i]));
}
EXPECT_EQ(map.contains(4), false);

for (int i = 0; i < 3; i++) {
EXPECT_EQ(map.get(arr[i]), arr[i]);
EXPECT_EQ(map.Size(), 3);
}

string sol = "key: 1 value: 1\nkey: 2 value: 2\nkey: 3 value: 3\n";
EXPECT_EQ(sol, map.toString());

for (int i = 0; i < 3; i++) {
EXPECT_EQ(map[arr[i]], arr[i]);
EXPECT_EQ(map.Size(), 3);
}
map[4];
EXPECT_EQ(map.Size(), 4);
map.clear();
EXPECT_EQ(map.toString(), "");
EXPECT_EQ(map.Size(), 0);
}

TEST(mymap, Milestone1_Everything) {
// test to compare with C++ map
mymap<int, int> mapMine;
map<int,int> mapSol;
int n = 1000000;  // # of elements inserted
// fill up BOTH maps
for (int i = 1; i <= n; i++) {
int key = rand() % n;  // given
int val = rand() % n;
mapMine.put(key, val);
mapSol[key] = val;
}
// 1. Assert sizes are equal
EXPECT_EQ(mapMine.Size(), mapSol.size());
// 2. String test (order is correct)
stringstream solution("");
// Fill string stream with mapSol
for (auto e : mapSol) {
solution << "key: " << e.first;
solution << " value: " << e.second << endl;
// 3. Test map contents
EXPECT_TRUE(mapMine.contains(e.first));
EXPECT_EQ(mapMine.get(e.first), e.second);
}
EXPECT_EQ(mapMine.toString(), solution.str());
}

TEST(mymap, two) {
// test to compare with C++ map
mymap<char, char> mapMine;
map<char,char> mapSol;
int n = 1000000;
for (int i = 1; i <= n; i++) {
int key = rand() % n;  // given
int val = rand() % n;
mapMine.put(key, val);
mapSol[key] = val;
}
EXPECT_EQ(mapMine.Size(), mapSol.size());
stringstream solution("");
for (auto e : mapSol) {
solution << "key: " << e.first;
solution << " value: " << e.second << endl;
EXPECT_TRUE(mapMine.contains(e.first));
EXPECT_EQ(mapMine.get(e.first), e.second);
}
EXPECT_EQ(mapMine.toString(), solution.str());
}

TEST(mymap, three) {
mymap<string, string> map;
string arr[] = {"Bob", "Bill", "Ben"};
for (int i = 0; i < 3; i++) {
map.put(arr[i], arr[i]);
}

EXPECT_EQ(map.Size(), 3);
for (int i = 0; i < 3; i++) {
EXPECT_TRUE(map.contains(arr[i]));
}
EXPECT_EQ(map.contains("Jack"), false);

for (int i = 0; i < 3; i++) {
EXPECT_EQ(map.get(arr[i]), arr[i]);
EXPECT_EQ(map.Size(), 3);
}

string sol = "key: Ben value: Ben\nkey: Bill value: Bill\nkey: Bob value: Bob\n";
EXPECT_EQ(sol, map.toString());

for (int i = 0; i < 3; i++) {
EXPECT_EQ(map[arr[i]], arr[i]);
EXPECT_EQ(map.Size(), 3);
}
map["Jack"];
EXPECT_EQ(map.Size(), 4);
}

TEST(mymap, four) {
mymap<double, double> map;
double arr[] = {5.5, 3.3, 2.2, 2.2};
double arr2[] = {5.5, 3.3, 2.2, 1.1};
for (int i = 0; i < 4; i++) {
map.put(arr[i], arr2[i]);
}

EXPECT_EQ(map.Size(), 3);
for (int i = 0; i < 4; i++) {
EXPECT_TRUE(map.contains(arr[i]));
}
EXPECT_EQ(map.contains(1.1), false);

for (int i = 0; i < 2; i++) {
EXPECT_EQ(map.get(arr[i]), arr2[i]);
EXPECT_EQ(map.Size(), 3);
}
EXPECT_EQ(map.get(arr[2]), arr2[3]);

string sol = "key: 2.2 value: 1.1\nkey: 3.3 value: 3.3\nkey: 5.5 value: 5.5\n";
EXPECT_EQ(sol, map.toString());

for (int i = 0; i < 2; i++) {
EXPECT_EQ(map[arr[i]], arr2[i]);
EXPECT_EQ(map.Size(), 3);
}
EXPECT_EQ(map[arr[2]], arr2[3]);
map[1.1];
EXPECT_EQ(map.Size(), 4);
}

TEST(mymap, five) {
mymap<int, int> map;
int arr[] = {2, 1, 3};
int order[] = {1, 2, 3};
for (int i = 0; i < 3; i++) {
map.put(arr[i], arr[i]);
}
int i = 0;
for (auto key : map) {
EXPECT_EQ(order[i++], key);
}
}

TEST(mymap, six) {
mymap<int, int> test;
map<int, int> correct;
int seed = 1000000;
for(int i = 0; i < 10000; i++) {
// randomize key and val
int k = rand() % seed;
int v = rand() % seed;
test.put(k, v);
correct[k] = v;
}
stringstream ss("");
for (int key : test) {
// it does work like this
ss << "key: " << key << " value: " << test[key] << endl;
}
// loop should be in order
ASSERT_EQ(test.toString(),ss.str());
}

TEST(mymap, seven) {
mymap<int,int> m;
for (int i=0;i<1000;i++) {
int x = rand() % 10000;
m.put(x, x);
EXPECT_NE(m.Size(), 0);
}
m.clear();
ASSERT_EQ(m.Size(), 0);
}

TEST(mymap, eight) {
mymap<int,int> m1;
for (int i=0;i<10;i++) {
int x = rand() % 10000;
m1.put(x, x);
}
mymap<int,int> m2;
m2 = m1;
ASSERT_EQ(m2.Size(), m1.Size());
ASSERT_EQ(m2.toString(),m1.toString());
}

TEST(mymap, nine) {
mymap<int,double> m1;
int arr[] = {3,2,4,1,5};
double arr2[] = {3.2, 2.2, 4.2, 1.2, 5.2};
for (int i=0;i<5;i++) {
m1.put(arr[i], arr2[i]);
}
mymap<int,double> mapCopy = m1;
for (int i=0;i<5;i++) {
ASSERT_EQ(mapCopy.contains(arr[i]), true);
}
for(int i=0; i<5; i++) {
ASSERT_EQ(mapCopy.get(arr[i]), arr2[i]);
}
ASSERT_EQ(mapCopy.Size(), m1.Size());
ASSERT_EQ(mapCopy.toString(),m1.toString());
}

TEST(mymap, ten) {
mymap<int,int> m1;
for (int i=0;i<10;i++) {
int x = rand() % 10000;
m1.put(x, x);
}
mymap<int,int> mapCopy = m1;
ASSERT_EQ(mapCopy.Size(), m1.Size());
ASSERT_EQ(mapCopy.toString(),m1.toString());
}

TEST(mymap, eleven) {
mymap<int,int> m;
vector<pair<int,int>> v;
int arr[] = {2,1,3};
for (int i=0;i<3;i++) {
  m.put(arr[i], arr[i]);
  v.push_back(make_pair(i+1,i+1));
}
ASSERT_EQ(m.toVector(), v);
}




