﻿/**
 * 李震
 * 我的码云：https://git.oschina.net/git-lizhen
 * 我的CSDN博客：http://blog.csdn.net/weixin_38215395
 * 联系：QQ1039953685
 */
#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H

#include <QThread>
#include <QImage>

class VlcInstance;
class VlcMedia;
class VlcMediaPlayer;

class VideoPlayer : public QThread
{
    Q_OBJECT

public:
    explicit VideoPlayer();
    ~VideoPlayer();

    void startPlay();

signals:
    void sig_GetOneFrame(QImage); //每获取到一帧图像 就发送此信号
    void sig_GetRFrame(QImage);

protected:
    void run();

private:
    QString mFileName;

    VlcInstance *_instance;
    VlcMedia *_media;
    VlcMediaPlayer *_player;
};

#endif // VIDEOPLAYER_H
