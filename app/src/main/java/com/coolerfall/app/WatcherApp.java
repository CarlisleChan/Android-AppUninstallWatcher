package com.coolerfall.app;

import android.app.Application;

import com.coolerfall.watcher.Watcher;

import java.util.HashMap;
import java.util.Map;

/**
 * Application of this project.
 *
 * @author Vincent Cheung
 * @since  Jan. 23, 2015
 */
public class WatcherApp extends Application {
	private static final String URL = "http://www.xiami.com/member/login";

	@Override
	public void onCreate() {
		super.onCreate();

		Map<String, String> test = new HashMap<String, String>() {{
			put("deviceId","111");
			put("imei","222");
			put("appId","33333333");
			put("serverId","1");
			put("appVersion","8.1.1");
		}};

		Watcher.run(this, URL, test, false);
	}
}
