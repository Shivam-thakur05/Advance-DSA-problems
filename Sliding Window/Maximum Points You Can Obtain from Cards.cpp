class Solution
{
public:
    int maxScore(vector<int> &cardPoints, int k)
    {
        int n = cardPoints.size();
        int score = 0;

        // Calculate the initial score for the first k elements.
        for (int i = 0; i < k; i++)
        {
            score += cardPoints[i];
        }

        int highScore = score;

        // Slide the window from the rightmost k cards back towards the left.
        for (int i = 0; i < k; i++)
        {
            score += cardPoints[n - 1 - i] - cardPoints[k - 1 - i];
            highScore = max(highScore, score);
        }

        return highScore;
    }
};
