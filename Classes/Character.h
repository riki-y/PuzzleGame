//
//  Character.h
//  PuzzleGame
//
//  Created by 吉田　理貴 on 2015/05/08.
//
//

#ifndef __PuzzleGame__Character__
#define __PuzzleGame__Character__

#include "cocos2d.h"

class Character : public cocos2d::Ref
{
public:
    // キャラクター属性
    enum class Element
    {
        Fire,
        Water,
        Wind,
        Holy,
        Shadow,
        None,
    };
    
protected:
    int _remainingTurn; // 攻撃するまでの残りターン
    CC_SYNTHESIZE(int, _hp, Hp); // ヒットポイント
    CC_SYNTHESIZE(int, _maxHp, MaxHp) // 最大ヒットポイント
    CC_SYNTHESIZE(int, _attack, Attack);
    CC_SYNTHESIZE(Element, _element, Element); // 属性
    CC_PROPERTY(int, _turnCount, TurnCount); // 攻撃ターン数
    
public:
    Character(); //コンストラクタ
    static Character* create(); // インスタンス生成
    
    float getHpPercentage(); // ヒットポイント(%値)取得
    bool isAttackTurn(); // 攻撃ターン(敵の場合)チェック
    static int getDamage(int ballCount, int chainCount, Character* attacker, Character* defender); // ダメージ数取得
    
protected:
    static float getElementBouns(Element attackElement, Element defenseElement); // 属性による攻撃ボーナス
};

#endif /* defined(__PuzzleGame__Character__) */
