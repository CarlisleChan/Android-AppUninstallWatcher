/*
 * File        : chttp.c
 * Author      : Vincent Cheung
 * Date        : Jan. 21, 2015
 * Description : This is file contains some http method.
 *
 * Copyright (C) Vincent Chueng<coolingfall@gmail.com>
 *
 */

#include <curl/curl.h>

#include "chttp.h"
#include "common.h"

#define LOG_TAG     "CHttp"

/** write callback of curl, we can get response body here */
static size_t write_callback(void *contents, size_t size, size_t nmemb, void *userp)
{
	LOGD(LOG_TAG, "response contents: %s", (char *) contents);
	return 0;
}

/**
 * C http request with get method.
 */
void chttp_get(char *url)
{
	LOGD(LOG_TAG, "get", &url);

	CURL *curl;
	CURLcode res;

	curl = curl_easy_init();
	if(curl)
	{
		curl_easy_setopt(curl, CURLOPT_URL, "http://www.baidu.com");
		/* follow redirection */
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
//		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);

		/* perform the request, res will get the return code */
		res = curl_easy_perform(curl);
		/* Check for errors */
		if(res != CURLE_OK)
		{
			LOGE(LOG_TAG, "curl perform failed: %s", curl_easy_strerror(res));
		}

		/* always cleanup */
		curl_easy_cleanup(curl);
		return;
	}

	LOGD(LOG_TAG, "curl init error");
}

void chttp_post(char *url, char *device_id, char *imei, char *app_id, char *server_id, char *app_version)
{
	LOGD(LOG_TAG, "post", &url);

	CURL *curl;
	CURLcode res;
	char post_fields[100];

	curl = curl_easy_init();
	strcat(post_fields, "deviceId=");
	strcat(post_fields, device_id);
	strcat(post_fields, "&imei=");
	strcat(post_fields, imei);
	strcat(post_fields, "&appId=");
	strcat(post_fields, app_id);
	strcat(post_fields, "&serverID=");
	strcat(post_fields, server_id);
	strcat(post_fields, "&appVersion=");
	strcat(post_fields, app_version);

	if(curl)
	{
//		curl_easy_setopt(curl, CURLOPT_URL, "http://test.tt.device.baidao.com/jry-device/login");
		curl_easy_setopt(curl, CURLOPT_URL, "http://www.xiami.com/member/login");
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
//        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "username=18668003173&password=111111");
		curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "/data/data/com.baidao.ytxmobile/curlposttest.cookie");

		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "email=390072835@qq.com&password=1111111");
		curl_easy_setopt(curl, CURLOPT_POST, 1);
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1);
		curl_easy_setopt(curl, CURLOPT_HEADER, 1);

		/* perform the request, res will get the return code */
		res = curl_easy_perform(curl);
		/* Check for errors */
		if(res != CURLE_OK)
		{
			LOGE(LOG_TAG, "curl perform failed: %s", curl_easy_strerror(res));
		}

		/* always cleanup */
		curl_easy_cleanup(curl);

		return;
	}

	LOGD(LOG_TAG, "curl init error");

}