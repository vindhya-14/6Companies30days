
class Solution {
public:
    bool asteroidsDestroyed(int mass, std::vector<int>& asteroids) {
        std::vector<std::pair<unsigned long long, unsigned long long>> ranges;
        std::vector<std::pair<unsigned long long, unsigned long long>> last_ranges;
        last_ranges.push_back(std::make_pair(0, static_cast<unsigned long long>(mass)));
        for (auto asteroid : asteroids) {
            unsigned long long asteroid_ull = static_cast<unsigned long long>(asteroid);
            int i;
            for (i = 0; i < last_ranges.size(); i++) {
                auto range = last_ranges[i];
                if (asteroid_ull <= range.second) {
                    break;
                }
                ranges.push_back(range);
            }
            if (i < last_ranges.size()) {
                std::pair<unsigned long long, unsigned long long> fold_result = std::make_pair(asteroid_ull, 2 * asteroid_ull);
                for (; i < last_ranges.size(); i++) {
                    auto range = last_ranges[i];
                    if (range.first <= fold_result.first && fold_result.first <= range.second) {
                        fold_result = std::make_pair(range.first, fold_result.second - fold_result.first + range.second);
                    } else if (range.first <= fold_result.second && fold_result.second <= range.second) {
                        fold_result = std::make_pair(fold_result.first, range.second - range.first + fold_result.second);
                    } else {
                        break;
                    }
                }
                ranges.push_back(fold_result);

                for (; i < last_ranges.size(); i++) {
                    ranges.push_back(last_ranges[i]);
                }

            } else {
                ranges.push_back(std::make_pair(asteroid_ull, 2 * asteroid_ull));
            }
            last_ranges.clear();
            std::swap(ranges, last_ranges);
        }
        return last_ranges.size() == 1;
    }
};