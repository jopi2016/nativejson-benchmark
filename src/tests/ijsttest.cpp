#include "../test.h"
#include <cstring>

#ifndef TEST_NAME
#define TEST_NAME "IJST (C++)"
#endif

#ifndef TEST_CLASS
#define TEST_CLASS ijstTest
#endif

#define IJST_ENABLE_TO_JSON_OBJECT			1
#define IJST_ENABLE_FROM_JSON_OBJECT		1

#include "IJST/include/ijst/ijst.h"
#include "IJST/include/ijst/types_std.h"
#include "IJST/include/ijst/types_container.h"
#include <rapidjson/prettywriter.h>
#include <iostream>

using namespace ijst;
using namespace std;
using namespace rapidjson;

#ifndef MAP_TYPE
#define MAP_TYPE	IJST_TOBJ
#endif // !MAP_TYPE

//=== canada
namespace canada {
	IJST_DEFINE_STRUCT(
			StGeometry
			, (T_string, type, "type", 0)
			, (IJST_TVEC(IJST_TVEC(IJST_TVEC(T_double))), coordinates, "coordinates", 0)
	);

	IJST_DEFINE_STRUCT(
			StFeature
			, (T_string, type, "type", 0)
			, (MAP_TYPE(T_string), properties, "properties", 0)
			, (IJST_TST(StGeometry), geometry, "geometry", 0)
	)

	IJST_DEFINE_STRUCT(
			StCanada
			, (T_string, type, "type", 0)
			, (IJST_TVEC(IJST_TST(StFeature)), features, "features", 0)
	)
}
typedef canada::StCanada StCanada;

//=== twitter
namespace twitter{
	IJST_DEFINE_STRUCT(
			StUser
			, (T_uint64, id, "id", 0)
			, (T_string, id_str, "id_str", 0)
			, (T_string, screen_name, "screen_name", FDesc::Nullable)
			, (T_string, location, "location", FDesc::Nullable)
			, (T_string, description, "description", FDesc::Nullable)
			, (T_string, url, "url", FDesc::Nullable)
			, (T_raw, entities, "entities", 0)
			, (T_bool, v_protected, "protected", 0)
			, (T_int, followers_count, "followers_count", 0)
			, (T_int, friends_count, "friends_count", 0)
			, (T_int, listed_count, "listed_count", 0)
			, (T_string, created_at, "created_at", 0)
			, (T_int, favourites_count, "favourites_count", 0)
			, (T_int, utc_offset, "utc_offset", FDesc::Nullable)
			, (T_string, time_zone, "time_zone", FDesc::Nullable)
			, (T_bool, geo_enabled, "geo_enabled", 0)
			, (T_bool, verified, "verified", 0)
			, (T_int, statuses_count, "statuses_count", 0)
			, (T_string, lang, "lang", 0)
			, (T_bool, contributors_enabled, "contributors_enabled", 0)
			, (T_bool, is_translator, "is_translator", 0)
			, (T_bool, is_translation_enabled, "is_translation_enabled", 0)
			, (T_string, profile_background_color, "profile_background_color", 0)
			, (T_string, profile_background_image_url, "profile_background_image_url", 0)
			, (T_string, profile_background_image_url_https, "profile_background_image_url_https", 0)
			, (T_bool, profile_background_tile, "profile_background_tile", 0)
			, (T_string, profile_image_url, "profile_image_url", 0)
			, (T_string, profile_image_url_https, "profile_image_url_https", 0)
			, (T_string, profile_banner_url, "profile_banner_url", FDesc::Optional)
			, (T_string, profile_link_color, "profile_link_color", 0)
			, (T_string, profile_sidebar_border_color, "profile_sidebar_border_color", 0)
			, (T_string, profile_sidebar_fill_color, "profile_sidebar_fill_color", 0)
			, (T_string, profile_text_color, "profile_text_color", 0)
			, (T_bool, profile_use_background_image, "profile_use_background_image", 0)
			, (T_bool, default_profile, "default_profile", 0)
			, (T_bool, default_profile_image, "default_profile_image", 0)
			, (T_bool, following, "following", 0)
			, (T_bool, follow_request_sent, "follow_request_sent", 0)
			, (T_bool, notifications, "notifications", 0)
	)

	IJST_DEFINE_STRUCT(
			StStatus
			, (MAP_TYPE(T_string), metadata, "metadata", 0)
			, (T_string, created_at, "created_at", 0)
			, (T_uint64, id, "id", 0)
			, (T_string, id_str, "id_str", 0)
			, (T_string, text, "text", 0)
			, (T_string, source, "source", 0)
			, (T_bool, truncated, "truncated", 0)
			, (T_uint64, in_reply_to_status_id, "in_reply_to_status_id", FDesc::Nullable)
			, (T_string, in_reply_to_status_id_str, "in_reply_to_status_id_str", FDesc::Nullable)
			, (T_uint64, in_reply_to_user_id, "in_reply_to_user_id", FDesc::Nullable)
			, (T_string, in_reply_to_user_id_str, "in_reply_to_user_id_str", FDesc::Nullable)
			, (T_string, in_reply_to_screen_name, "in_reply_to_screen_name", FDesc::Nullable)
			, (IJST_TST(StUser), user, "user", 0)
			, (T_string, geo, "geo", FDesc::Nullable)
			, (T_string, coordinates, "coordinates", FDesc::Nullable)
			, (T_string, place, "place", FDesc::Nullable)
			, (T_string, contributors, "contributors", FDesc::Nullable)
			, (T_int, retweet_count, "retweet_count", 0)
			, (T_int, favorite_count, "favorite_count", 0)
			, (T_raw, entities, "entities", 0)
			, (T_bool, favorited, "favorited", 0)
			, (T_bool, retweeted, "retweeted", 0)
			, (T_string, lang, "lang", 0)
	)

	IJST_DEFINE_STRUCT(
			StSearchMetaData
			, (T_double, completed_in, "completed_in", 0)
			, (T_uint64, max_id, "max_id", 0)
			, (T_string, max_id_str, "max_id_str", 0)
			, (T_string, next_results, "next_results", 0)
			, (T_string, query, "query", 0)
			, (T_string, refresh_url, "refresh_url", 0)
			, (T_int, count, "count", 0)
			, (T_uint64, since_id, "since_id", 0)
			, (T_string, since_id_str, "since_id_str", 0)
	)

	IJST_DEFINE_STRUCT(
			StTwitter
			, (IJST_TVEC(IJST_TST(StStatus)), statuses, "statuses", 0)
			, (IJST_TST(StSearchMetaData), search_metadata, "search_metadata", 0)
	)
}
typedef twitter::StTwitter StTwitter;

namespace citm_catalog {
	IJST_DEFINE_STRUCT(
			StEvent
			, (T_string, description, "description", FDesc::Nullable)
			, (T_uint64, id, "id", 0)
			, (T_string, logo, "logo", FDesc::Nullable)
			, (T_string, name, "name", 0)
			, (IJST_TVEC(T_uint64), subTopicIds, "subTopicIds", 0)
			, (T_int, subjectCode, "subjectCode", FDesc::Nullable)
			, (T_string, subtitle, "subtitle", FDesc::Nullable)
			, (IJST_TVEC(T_uint64), topicIds, "topicIds", 0)
	)

	IJST_DEFINE_STRUCT(
			StPrice
			, (T_int, amount, "amount", 0)
			, (T_int64, audienceSubCategoryId, "audienceSubCategoryId", 0)
			, (T_int64, seatCategoryId, "seatCategoryId", 0)
	)

	IJST_DEFINE_STRUCT(
			StArea
			, (T_uint64, areaId, "areaId", 0)
			, (IJST_TVEC(T_uint64), blockIds, "blockIds", 0)
	)

	IJST_DEFINE_STRUCT(
			StSeatCategory
			, (IJST_TVEC(IJST_TST(StArea)), areas, "areas", 0)
			, (T_uint64, seatCategoryId, "seatCategoryId", 0)
	)

	IJST_DEFINE_STRUCT(
			StPerformance
			, (T_uint64, eventId, "eventId", 0)
			, (T_uint64, id, "id", 0)
			, (T_string, logo, "logo", FDesc::Nullable)
			, (T_string, name, "name", FDesc::Nullable)
			, (IJST_TVEC(IJST_TST(StPrice)), prices, "prices", 0)
			, (IJST_TVEC(IJST_TST(StSeatCategory)), seatCategories, "seatCategories", 0)
			, (T_string, seatMapImage, "seatMapImage", FDesc::Nullable)
			, (T_uint64, start, "start", 0)
			, (T_string, venueCode, "venueCode", 0)
	)

	IJST_DEFINE_STRUCT(
			StCitmCatalog
			, (MAP_TYPE(T_string), areaNames, "areaNames", 0)
			, (MAP_TYPE(T_string), audienceSubCategoryNames, "audienceSubCategoryNames", 0)
			, (MAP_TYPE(T_string), blockNames, "blockNames", 0)
			, (MAP_TYPE(IJST_TST(StEvent)), events, "events", 0)
			, (IJST_TVEC(IJST_TST(StPerformance)), performamces, "performances", 0)
			, (MAP_TYPE(T_string), seatCategoryNames, "seatCategoryNames", 0)
			, (MAP_TYPE(T_string), subTopicNames, "subTopicNames", 0)
			, (MAP_TYPE(T_string), subjectNames, "subjectNames", 0)
			, (MAP_TYPE(T_string), topicNames, "topicNames", 0)
			, (MAP_TYPE(IJST_TVEC(T_uint64)), topicSubTopics, "topicSubTopics", 0)
			, (MAP_TYPE(T_string), venueNames, "venueNames", 0)
	)
}
typedef citm_catalog::StCitmCatalog StCitmCatalog;

IJST_DEFINE_STRUCT(
		StCommon
);

IJST_DEFINE_VALUE(
		StVal, T_raw, v, 0
)

IJST_DEFINE_VALUE(
		VecDouble, IJST_TVEC(T_double), v, 0
)

IJST_DEFINE_VALUE(
		VecStr, IJST_TVEC(T_string), v, 0
)

template <typename Encoding = UTF8<> >
class StatHandler : public BaseReaderHandler<Encoding, StatHandler<Encoding> > {
public:
	typedef typename Encoding::Ch Ch;

	StatHandler(Stat& stat) : stat_(stat) {}

	bool Null() { stat_.nullCount++; return true; }
	bool Bool(bool b) { if (b) stat_.trueCount++; else stat_.falseCount++; return true; }
	bool Int(int) { stat_.numberCount++; return true; }
	bool Uint(unsigned) { stat_.numberCount++; return true; }
	bool Int64(int64_t) { stat_.numberCount++; return true; }
	bool Uint64(uint64_t) { stat_.numberCount++; return true; }
	bool Double(double) { stat_.numberCount++; return true; }
	bool String(const Ch*, SizeType length, bool) { stat_.stringCount++; stat_.stringLength += length; return true; }
	bool StartObject() { return true; }
	bool EndObject(SizeType memberCount) { stat_.objectCount++; stat_.memberCount += memberCount; return true; }
	bool StartArray() { return true; }
	bool EndArray(SizeType elementCount) { stat_.arrayCount++; stat_.elementCount += elementCount; return true; }

private:
	StatHandler& operator=(const StatHandler&);

	Stat& stat_;
};

class ijstStringResult : public StringResultBase {
public:
	ijstStringResult(string* _str) : str(_str) {}
	~ijstStringResult() {delete str;}
	virtual const char* c_str() const { return str->c_str(); }

	string* str;
};

class ijstStringBufResult : public StringResultBase {
public:
	ijstStringBufResult(rapidjson::StringBuffer* _buf) : buf(_buf) {}
	~ijstStringBufResult() {delete buf;}
	virtual const char* c_str() const { return buf->GetString(); }

	rapidjson::StringBuffer* buf;
};

class ijstParseResultBase : public ParseResultBase {
public:
	virtual StringResultBase* Stringify() const = 0;
	virtual bool GenStat(Stat* stat) const = 0;
	virtual StringResultBase* Prettify() const = 0;
};

template <typename T>
class ijstParseResult : public ijstParseResultBase {
public:
	ijstParseResult(T* _val = IJST_NULL) : st(_val)
	{
	}

	StringResultBase* Stringify() const override {
		string* out = new string();
		int ret = st->_.Serialize(*out, SerFlag::kOnlyValidField);
		if (ret != 0) {
			delete out;
			return NULL;
		}

		return new ijstStringResult(out);
	}

	StringResultBase* Prettify() const override {
		rapidjson::StringBuffer* buf = new rapidjson::StringBuffer();
		rapidjson::PrettyWriter<rapidjson::StringBuffer> writer(*buf);
		ijst::HandlerWrapper<rapidjson::PrettyWriter<rapidjson::StringBuffer> > writerWrapper(writer);
		int ret = st->_.Serialize(writerWrapper, SerFlag::kOnlyValidField);
		if (ret != 0) {
			delete buf;
			return NULL;
		}

		return new ijstStringBufResult(buf);
	}

	bool GenStat(Stat* stat) const override {
		memset(stat, 0, sizeof(Stat));
		StatHandler<> h(*stat);
		HandlerWrapper<StatHandler<> > writerWrapper(h);
		if(st->_.Serialize(writerWrapper, SerFlag::kOnlyValidField) != 0) {
			return false;
		}
		return true;
	}

	~ijstParseResult() { delete st; }
	T* st;
};


template<typename T>
ijstParseResultBase* GetParseResult(const char* json, size_t length, bool print_err = true)
{
	T* val = new T();
	Document errDoc;
	int ret = val->_.Deserialize(json, length, DeserFlag::kNoneFlag, &errDoc);
	if (ret != 0) {
		if (print_err) {
			StringBuffer sb;
			Writer<StringBuffer> writer;
			errDoc.Accept(writer);
			cout << "Deserialize error:  "  << sb.GetString() << endl;
		}
		delete val;
		return 0;
	}
	return new ijstParseResult<T>(val);
}


class TEST_CLASS : public TestBase {
public:
#if TEST_INFO
	virtual const char* GetName() const { return TEST_NAME; }
	virtual const char* GetFilename() const { return __FILE__; }
#endif

#if TEST_PARSE
	virtual ParseResultBase* Parse(const char* json, size_t length, const char* case_name) const {
//		cout << case_name << endl;
		if (strcmp(case_name, "canada.json") == 0) {
			return GetParseResult<StCanada>(json, length);
		}
		else if (strcmp(case_name, "twitter.json") == 0) {
			return GetParseResult<StTwitter>(json, length);
		}
		else if(strcmp(case_name, "citm_catalog.json") == 0) {
			return GetParseResult<StCitmCatalog>(json, length);
		}
		else if (strstr(case_name, "jsonchecker") != NULL) {
			return GetParseResult<StVal>(json, length, false);
		}
		else if (strstr(case_name, "roundtrip") != NULL) {
			return GetParseResult<StVal>(json, length);
		}
		else {
			return GetParseResult<StCommon>(json, length);
		}
	}
#endif

#if TEST_STRINGIFY
	virtual StringResultBase* Stringify(const ParseResultBase* parseResult) const {
		const ijstParseResultBase *result = dynamic_cast<const ijstParseResultBase*>(parseResult);
		return result->Stringify();
	}
#endif

#if TEST_PRETTIFY
	virtual StringResultBase* Prettify(const ParseResultBase* parseResult) const {
		const ijstParseResultBase *result = dynamic_cast<const ijstParseResultBase*>(parseResult);
		return result->Prettify();
	}
#endif

#if TEST_STATISTICS
	virtual bool Statistics(const ParseResultBase* parseResult, Stat* stat) const {
		const ijstParseResultBase *result = dynamic_cast<const ijstParseResultBase*>(parseResult);
		return result->GenStat(stat);
	}
#endif

/*
#if TEST_SAXROUNDTRIP
	virtual StringResultBase* SaxRoundtrip(const char* json, size_t length) const {
		(void)length;
		Reader reader;
		RapidjsonStringResult* sr = new RapidjsonStringResult;
		Writer<StringBuffer> writer(sr->sb);

#ifdef TEST_INSITU
		RapidjsonParseResult pr(json, length);
        InsituStringStream is(pr.buffer);
#else
		StringStream is(json);
#endif

		if (!reader.Parse<TEST_PARSE_FLAG>(is, writer)) {
			delete sr;
			return 0;
		}
		return sr;
	}
#endif

#if TEST_SAXSTATISTICS
	virtual bool SaxStatistics(const char* json, size_t length, Stat* stat) const {
		(void)length;
		memset(stat, 0, sizeof(Stat));
		Reader reader;

#ifdef TEST_INSITU
		RapidjsonParseResult pr(json, length);
        InsituStringStream is(pr.buffer);
#else
		StringStream is(json);
#endif

		StatHandler<> handler(*stat);
		return reader.Parse<TEST_PARSE_FLAG>(is, handler);
	}
#endif

#if TEST_SAXSTATISTICSUTF16
	virtual bool SaxStatisticsUTF16(const char* json, size_t length, Stat* stat) const {
		(void)length;
		memset(stat, 0, sizeof(Stat));
		GenericReader<UTF8<>, UTF16<> > reader;

#ifdef TEST_INSITU
		RapidjsonParseResult pr(json, length);
        InsituStringStream is(pr.buffer);
#else
		StringStream is(json);
#endif
		StatHandler<UTF16<> > handler(*stat);
		return reader.Parse<TEST_PARSE_FLAG>(is, handler);
	}
#endif
 */

#if TEST_CONFORMANCE
	virtual bool ParseDouble(const char* json, double* d) const {
		VecDouble v;
		int ret;
#ifdef TEST_INSITU
		ret = v._.DeserializeInsitu(json);
#else
		ret = v._.Deserialize(json, strlen(json));
#endif
		if (ret != 0) {
			return false;
		}
		*d = v.v[0];
		return true;
	}

	virtual bool ParseString(const char* json, std::string& s) const {
		VecStr v;
		int ret;
#ifdef TEST_INSITU
		ret = v._.DeserializeInsitu(json);
#else
		ret = v._.Deserialize(json, strlen(json));
#endif
		if (ret != 0) {
			return false;
		}
		s = v.v[0];
		return true;
	}
#endif
};
REGISTER_TEST(TEST_CLASS);

